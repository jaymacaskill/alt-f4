// Dian le Roux (25147065)
// Marko de Swardt (24658562)
// Jay Macaskill (25198387)

// COS 214 (Software Modelling) Practical 3
// Last Modified: 29 August 2026

// main.cpp

#include "EventComponent.h"
#include "EventGroup.h"
#include "EventUnit.h"

#include "GameFest.h"

#include "MainHall.h"
#include "MainStage.h"
#include "TicketGate.h"
#include "RetroCorner.h"
#include "ArcadeRow.h"

#include "TournamentWing.h"
#include "eSportsArena.h"
#include "Queue.h"

#include "VendorHall.h"
#include "MerchStall.h"
#include "DemoStation.h"

#include "Subject.h"
#include "Observer.h"
#include "ControlDesk.h"

#include "Notice.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Demonstrates that anonymous objects are safely deleted by the Composite destructor
 */
void anonymous_example()
{
    // Level 3: Sub-area
    RetroCorner* retro_corner = new RetroCorner;
        retro_corner->add(new ArcadeRow("Arcade Row", 5)); // owns anonymous arcade row

    // Level 2: Halls
    MainHall* main_hall = new MainHall;
        main_hall->add(retro_corner); // owns retro corner and arcade row
        main_hall->add(new TicketGate("Ticket Gate", 35)); // owns ticket gate as well
        main_hall->add(new MainStage("Main Stage", 25)); // owns main stage as well

    TournamentWing* tournament_wing = new TournamentWing;
        tournament_wing->add(new Queue("Tournament Queue", 30)); // owns anonymous tournament queue
        tournament_wing->add(new eSportsArena("eSportsArena", 10)); // owns anonymous eSportsArena

    VendorHall* vendor_hall = new VendorHall;
        vendor_hall->add(new MerchStall("Adventure Time", 15)); // owns anonymous merch stalls
        vendor_hall->add(new MerchStall("Minecraft", 15));
        vendor_hall->add(new DemoStation("Mortal Kombat", 8));
        vendor_hall->add(new DemoStation("Paralives", 5)); // owns anonymous demo stations

    // Level 1: Root
    GameFest* game_fest = new GameFest; // root (owns everything now)
        game_fest->add(main_hall);
        game_fest->add(tournament_wing);
        game_fest->add(vendor_hall);

    delete game_fest;

// note that the destructor allows us to use anonymous objects and safely delete as above
// but so we can call functions on objects, we do not use this approach for the demo
}

int main()
{
    anonymous_example();

    // === CREATE EVENT (with small capacities) === //

    // --- Leaves (Level 4) ---
    TicketGate* ticket_gate = new TicketGate("Ticket Gate", 35);
    MainStage* main_stage = new MainStage("Main Stage", 25);
    ArcadeRow* arcade_row = new ArcadeRow("Arcade Row", 5);

    Queue* tournament_queue = new Queue("Tournament Queue", 30);
    eSportsArena* arena = new eSportsArena("eSportsArena", 10);

    MerchStall* adventure_time = new MerchStall("Adventure Time", 15);
    MerchStall* minecraft = new MerchStall("Minecraft", 15);
    DemoStation* mortal_kombat = new DemoStation("Mortal Kombat", 8);
    DemoStation* paralives = new DemoStation("Paralives", 5);

    // --- Sub-areas (Level 3) ---
    RetroCorner* retro_corner = new RetroCorner;
        retro_corner->add(arcade_row);

    // --- Halls/Wings (Level 2) ---
    MainHall* main_hall = new MainHall;
        main_hall->add(retro_corner);
        main_hall->add(ticket_gate);
        main_hall->add(main_stage);

    TournamentWing* tournament_wing = new TournamentWing;
        tournament_wing->add(tournament_queue);
        tournament_wing->add(arena);

    VendorHall* vendor_hall = new VendorHall;
        vendor_hall->add(adventure_time);
        vendor_hall->add(minecraft);
        vendor_hall->add(mortal_kombat);
        vendor_hall->add(paralives);

    // --- Root (Level 1) ---
    GameFest* game_fest = new GameFest; // root (owns everything now)
        game_fest->add(main_hall);
        game_fest->add(tournament_wing);
        game_fest->add(vendor_hall);

    // --- Control Desk ---
    ControlDesk* control_desk = new ControlDesk;
        control_desk->attach(game_fest); // in the add function of EventGroup
    // the added EventComponent will be added to the list of observers of that EventGroup

    // ==== HERE WE TEST DUPLICATE ATTACHING! ===== ///
        control_desk->attach(game_fest); // this must be handled correctly

    // STORY: A Day at GameFest

    cout << "\n===== " << game_fest->getName() << " =====\n";

    /* currently, GameFest is closed */
    cout << "\n📋 GameFest is currently closed:" << endl;
    game_fest->reportStatus();

    // ==== OPEN THE FESTIVAL ==== //

    cout << "\n🔓 GameFest is opening! 🎮" << endl;

    Notice open;
    open.message = "Open the festival!";
    open.type = OPEN;

    control_desk->issueNotice(open);
    // this means that one notify will cascade all the way to every single EventComponent
    // this will be shown by the print messages of each open()
    // benefit of push model, this is all we need to do for a notification

    // ==== TICKET GATE: Admit/Dismiss ==== //

    cout << "\n===== " << ticket_gate->getName() << " =====\n";
    cout << "🎟️ Ten people have arrived at the ticket gate." << endl;

    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();
    ticket_gate->admit();

    ticket_gate->reportStatus();

    cout << "\n🚪 Ten people are let through..." << endl;

    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();
    ticket_gate->dismiss();

    cout << "\n😴 Everyone has been let in, but a sleepy worker accidentally let in 11 people..." << endl;
    ticket_gate->dismiss();

    // ==== MAIN HALL ==== //

    cout << "\n===== " << main_hall->getName() << " =====\n";
    cout << "👨‍👩‍👦 Timmy's parents have gone to the Main Stage, while little Timmy visits the Arcade Row." << endl;

    main_stage->admit();
    main_stage->admit();
    arcade_row->admit();

    // ==== VENDOR HALL ==== //

    cout << "\n===== " << vendor_hall->getName() << " =====\n";
    cout << "🛍️ At the Vendor Hall, every demo station and merch stall has someone interested!" << endl;

    adventure_time->admit();
    minecraft->admit();
    mortal_kombat->admit();
    paralives->admit();

    // ==== NETWORK ERROR ==== //

    cout << "\n💻 While Noah was paying for his Adventure Time poster, there was a network error..." << endl;

    Notice network_error;
    network_error.message = "Please hold on while our technicians resolve the network error";
    network_error.type = NETWORK_ERROR;

    control_desk->issueNotice(network_error);

    cout << "\n✅ Which was thankfully resolved quickly! After which many people went to the Main Hall." << endl;

    adventure_time->dismiss();
    minecraft->dismiss();
    paralives->dismiss();
    mortal_kombat->dismiss();

    main_stage->admit();
    arcade_row->admit();
    arcade_row->admit();
    main_stage->admit();

    network_error.message = "The network error has been resolved";
    network_error.type = NETWORK_RESTORED;

    control_desk->issueNotice(network_error);

    // ==== SECURITY ANNOUNCEMENT ==== //

    cout << "\n🚗 Someone left their car window open in the parking lot!" << endl;

    Notice car_window;
    car_window.message = "There is a purple Dodge Charger with their window down in the parking lot";
    car_window.type = SECURITY_ANNOUNCEMENT;

    control_desk->issueNotice(car_window);

    // ==== TOURNAMENT WING ==== //

    cout << "\n===== " << tournament_wing->getName() << " =====\n";
    cout << "🎮 Nora and Andy join the queue for the tournament..." << endl;

    tournament_queue->admit();
    tournament_queue->admit();
    tournament_queue->admit();

    cout << "\n⚡ While Nora and Andy are waiting to get let in to the tournament, the power fails!" << endl;

    Notice power;
    power.message = "Please stand by while our technicians resolve the power issues";
    power.type = POWER_ALERT;

    control_desk->issueNotice(power);

    tournament_queue->dismiss();
    tournament_queue->dismiss();

    cout << "\n🛠️ Thankfully, the technicians got a nice bonus and have been very efficient ever since." << endl;

    power.message = "Our technical team has resolved the crisis";
    power.type = POWER_STABILISED;

    control_desk->issueNotice(power);

    cout << "\n🎯 Nora and Andy play their game, Andy is winning!" << endl;

    arena->admit();
    arena->admit();


    // ==== TRANSFER: Merch Stall moves ==== //

    cout << "\n📦 The Merch Stall gets moved to the Main Hall..." << endl;

    vendor_hall->transfer(main_hall, adventure_time); // this also needs to dismiss merch_stall from being owned by vendor_hall


    // ==== VENDOR CLOSE ==== //

    cout << "\n🏪 The vendors decided this is way too unorganised, the Vendor Hall closed early..." << endl;

    Notice vendor_close;
    vendor_close.message = "The vendors all went home";
    vendor_close.type = VENDOR_CLOSE;

    control_desk->issueNotice(vendor_close);

    // the remove function must return the removed item so we can delete orphans
    game_fest->remove(vendor_hall);
    main_hall->remove(adventure_time);

    delete vendor_hall;
    delete adventure_time; // since main has pointers, this is fine


    // ==== MORE ATTENDEES ==== //

    cout << "\n🎟️ Some more people are queuing at the ticket gate. GameFest is still a great success!" << endl;

    ticket_gate->admit();
    ticket_gate->admit();


    // ==== FINAL STATUS ==== //

    cout << "\n📋 Final event status:" << endl;
    game_fest->reportStatus(); // must loop over children (and have a total capacity, similar to EventUnit reportCapacity)


    // ==== LOST PERSON ==== //

    cout << "\n🔍 Timmy's parents have lost little Timmy..." << endl;

    Notice lost_child;
    lost_child.message = "Little Timmy. 7 year old boy. Ginger. Blue eyes. Last seen at Arcade Row.";
    lost_child.type = LOST_PERSON;

    control_desk->issueNotice(lost_child);


    // ==== EVACUATE ==== //

    cout << "\n🚨 Good news is they found Timmy. Bad news is we need to evacuate, NOW." << endl;

    Notice evacuate;
    evacuate.message = "Emergency evacuation in progress. Please exit calmly.";
    evacuate.type = EVACUATE;

    control_desk->issueNotice(evacuate);

    cout << "\n🧹 Cleaning up..." << endl;

    control_desk->detach(game_fest);

    // ==== HERE WE TEST NONSENSICAL DETACHING ==== ///
    control_desk->detach(ticket_gate); // this must be ignored safely

    delete game_fest; // in event group destructor we must clear observers, delete children, then clear children
    delete control_desk;

    cout << "\n🎮 GameFest simulation complete!" << endl;

    return 0;
}