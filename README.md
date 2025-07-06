✈️ Airport Flight Reservation System (C++ Project)
This is a console-based Flight Reservation System written in C++ that allows Passengers to register, log in, and reserve/cancel seats on Local or International flights. Admins can add or remove flights, view flight schedules, reset user passwords, and manage airplane seating under normal and COVID/SOP conditions.

🚀 Features
👨‍💼 Admin Panel
Add Local and International flights

Remove existing flights

View all flights (with custom schedule format)

Reset any user's password

Show seating arrangement of an airplane

Enforce Corona SOPs (alternate seat disabling)

View system summary (e.g. cities/airports involved)

👤 Passenger Panel
Register and log in securely

Reset own password

Reserve seats on Local or International flights

View detailed ticket with flight info after reservation

Cancel reservations (with penalty deduction)

View all available flights

🛫 Flight Management
Two flight types: Local and International

Each flight is linked to:

A departure and arrival airport

An assigned aeroplane

Distance, Duration, Departure and Arrival time

Seat reservation is visualized using seating maps

🪑 Seating System
Airplane seating is grid-based (12x5)

Corona mode disables alternate seats for SOPs

Seats marked as:

|B| for Business Class

|E| for Economy Class

|X| for reserved

|.| for disabled due to Corona SOPs

🛠️ Technologies Used
Language: C++

OOP Concepts: Classes, Inheritance, Polymorphism

Data Management: File I/O for users

UI: Console-based UI with ASCII art and menus


Passenger Menu:
| 1)- Reset Password      |
| 2)- Reserve a seat      |
| 3)- Cancel a seat       |
| 4)- See Flight Schedule |
| 6)- Exit                |

Admin Panel:
| 1)- Add Flight               |
| 2)- Remove Flight            |
| 3)- View Flight Schedule     |
| 4)- Reset Password           |
| 5)- View System Summary      |
| 6)- Seating Arrangements     |
| 7)- Exit                     |

📝 Notes
Passwords and usernames are stored using file I/O.

Use valid input formats — exceptions are handled for incorrect entries.

The system dynamically allocates and deallocates memory for flights and airplanes.

Make sure to clean up memory to avoid leaks.
