//**************************** <- AirLine System -> ****************************//
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;

int main()
{


	//Islamabad North Airport 
	Aeroplane Boeing_737("Boeing_737", 1);
	Aeroplane Airbus_A320("Airbus_A320", 1);
	Aeroplane Boeing_747("Boeing_747", 1);
	Aeroplane Airbus_A380("Airbus_A380", 1);
	Aeroplane Boeing_787("Boeing_787", 1);

	//Islamabad South Airport
	Aeroplane Embraer_E190("Embraer_E190", 1);
	Aeroplane Fokker_F27("Fokker_F27", 1);
	Aeroplane Fokker_F28("Fokker_F28", 1);
	Aeroplane ATR_42("ATR_42", 1);
	Aeroplane ATR_72("ATR_72", 1);


	Airport North_Islamabad(&Boeing_737, &Airbus_A320, &Boeing_747, &Airbus_A380, &Boeing_787, 0);
	Airport South_Islamabad(&Embraer_E190, &Fokker_F27, &Fokker_F28, &ATR_42, &ATR_72, 0);
	City Islamabad("Islamabad", &North_Islamabad, &South_Islamabad);
	North_Islamabad.setAirportName("North_Islamabad");
	South_Islamabad.setAirportName("South_Islamabad");

	// Lahore North airport
	Aeroplane Airbus_A321("Airbus_A321", 0);
	Aeroplane Boeing_767("Boeing_767", 0);
	Aeroplane McDonnell_Douglas_MD11("McDonnell_Douglas_MD11", 0);
	Aeroplane McDonnell_Douglas_MD90("McDonnell_Douglas_MD90", 0);
	Aeroplane Boeing_777("Boeing_777", 0);

	// Lahore South airport
	Aeroplane Airbus_A330("Airbus_A330", 0);
	Aeroplane Boeing_757("Boeing_757", 0);
	Aeroplane McDonnell_Douglas_DC10("McDonnell_Douglas_DC10", 0);
	Aeroplane McDonnell_Douglas_MD80("McDonnell_Douglas_MD80", 0);
	Aeroplane Airbus_A340("Airbus_A340", 0);

	Airport North_Lahore(&Airbus_A321, &Boeing_767, &McDonnell_Douglas_MD11, &McDonnell_Douglas_MD90, &Boeing_777, 0);
	Airport South_Lahore(&Airbus_A330, &Boeing_757, &McDonnell_Douglas_DC10, &McDonnell_Douglas_MD80, &Airbus_A340, 0);

	City Lahore("Lahore", &North_Lahore, &South_Lahore);

	North_Lahore.setAirportName("North_Lahore");
	South_Lahore.setAirportName("South_Lahore");

	// Karachi North airport
	Aeroplane Boeing_737_800("Boeing_737_800", 0);
	Aeroplane Boeing_747_400("Boeing_747_400", 0);
	Aeroplane Airbus_A300("Airbus_A300", 0);
	Aeroplane Airbus_A310("Airbus_A310", 0);
	Aeroplane Airbus_A320neo("Airbus_A320neo", 0);

	// Karachi South airport
	Aeroplane Boeing_757_200("Boeing_757_200", 0);
	Aeroplane Boeing_777_200("Boeing_777_200", 0);
	Aeroplane Airbus_A321neo("Airbus_A321neo", 0);
	Aeroplane Airbus_A330_200("Airbus_A330_200", 0);
	Aeroplane Airbus_A350_900("Airbus_A350_900", 0);

	Airport North_Karachi(&Boeing_737_800, &Boeing_747_400, &Airbus_A300, &Airbus_A310, &Airbus_A320neo, 0);
	Airport South_Karachi(&Boeing_757_200, &Boeing_777_200, &Airbus_A321neo, &Airbus_A330_200, &Airbus_A350_900, 0);

	City Karachi("Karachi", &North_Karachi, &South_Karachi);

	North_Karachi.setAirportName("North_Karachi");
	South_Karachi.setAirportName("South_Karachi");
	// Peshawar North airport
	Aeroplane Embraer_E195("Embraer_E195", 0);
	Aeroplane Antonov_An148("Antonov_An148", 0);
	Aeroplane Antonov_An158("Antonov_An158", 0);
	Aeroplane Ilyushin_Il76("Ilyushin_Il76", 0);
	Aeroplane Tupolev_Tu154("Tupolev_Tu154", 0);

	// Peshawar South airport
	Aeroplane Saab_2000("Saab_2000", 0);
	Aeroplane ATR_72_500("ATR_72_500", 0);
	Aeroplane Antonov_An72("Antonov_An72", 0);
	Aeroplane Yakovlev_Yak40("Yakovlev_Yak40", 0);
	Aeroplane Let_L410("Let_L410", 0);

	Airport North_Peshawar(&Embraer_E195, &Antonov_An148, &Antonov_An158, &Ilyushin_Il76, &Tupolev_Tu154, 0);
	Airport South_Peshawar(&Saab_2000, &ATR_72_500, &Antonov_An72, &Yakovlev_Yak40, &Let_L410, 0);

	City Peshawar("Peshawar", &North_Peshawar, &South_Peshawar);

	North_Peshawar.setAirportName("North_Peshawar");
	South_Peshawar.setAirportName("South_Peshawar");

	// Quetta North airport
	Aeroplane Boeing_727("Boeing_727", 0);
	Aeroplane Boeing_750("Boeing_750", 0);
	Aeroplane McDonnell_Douglas_DC11("McDonnell_Douglas_DC11", 0);
	Aeroplane McDonnell_Douglas_MD22("McDonnell_Douglas_MD11", 0);
	Aeroplane Lockheed_L1011("Lockheed_L1011", 0);

	// Quetta South airport
	Aeroplane Bombardier_CRJ900("Bombardier_CRJ900", 0);
	Aeroplane Canadair_CL215("Canadair_CL215", 0);
	Aeroplane Canadair_CL415("Canadair_CL415", 0);
	Aeroplane Antonov_An26("Antonov_An26", 0);
	Aeroplane Antonov_An74("Antonov_An74", 0);

	Airport North_Quetta(&Boeing_727, &Boeing_757, &McDonnell_Douglas_DC10, &McDonnell_Douglas_MD11, &Lockheed_L1011, 0);
	Airport South_Quetta(&Bombardier_CRJ900, &Canadair_CL215, &Canadair_CL415, &Antonov_An26, &Antonov_An74, 0);

	City Quetta("Quetta", &North_Quetta, &South_Quetta);
	North_Quetta.setAirportName("North_Quetta");
	South_Quetta.setAirportName("South_Quetta");

	Country Pakistan(&Islamabad, &Peshawar, &Lahore, &Karachi, &Quetta);

	//Foreign Airports 
	Airport SaudiArabia("SaudiArabia");
	Airport Yemen("Yemen");
	Airport Oman("Oman");
	Airport Bahrain("Bahrain");
	Airport Qatar("Qatar");
	Airport Kuwait("Kuwait");
	Airport Iran("Iran");
	Airport China("China");
	Airport Turkey("Turkey");
	Airport Malaysia("Malaysia");
	Airport Singapore("Singapore");
	Airport Thailand("Thailand");
	Airport Indonesia("Indonesia");
	Airport India("India");
	Airport Bangladesh("Bangladesh");
	Airport Nepal("Nepal");
	Airport Srilanka("Srilanka");
	Airport Egypt("Egypt");
	Airport Morocco("Morocco");
	Airport Sudan("Sudan");
	Airport Russia("Russia");
	Airport UK("UK");
	Airport Germany("Germany");
	Airport France("France");
	Airport Italy("Italy");






	DisplayFlights D;

	//Local Flights 

	//Islamabad

	//North 
	//Islamabad

	//North 
	LocalFlight Boeing_737F1(&North_Islamabad, &North_Karachi, &Boeing_737, 2.45, 1200, "00:00", "02:00");
	LocalFlight Boeing_737F2(&North_Karachi, &North_Peshawar, &Boeing_737, 2.1, 1200, "04:00", "06:00");
	LocalFlight Boeing_737F3(&North_Peshawar, &North_Quetta, &Boeing_737, 2.2, 1200, "08:00:AM", "10:00");
	LocalFlight Boeing_737F4(&North_Quetta, &North_Lahore, &Boeing_737, 2.5, 1200, "12:00", "14:00");
	LocalFlight Boeing_737F5(&North_Lahore, &North_Islamabad, &Boeing_737, 2.46, 1200, "16:00", "18:00");

	D.addLocalFlight(&Boeing_737F1);
	D.addLocalFlight(&Boeing_737F2);
	D.addLocalFlight(&Boeing_737F3);
	D.addLocalFlight(&Boeing_737F4);
	D.addLocalFlight(&Boeing_737F5);



	LocalFlight Airbus_A320F1(&North_Islamabad, &South_Karachi, &Airbus_A320, 2.7, 1200, "01:00", "03:00");
	LocalFlight Airbus_A320F2(&South_Karachi, &South_Peshawar, &Airbus_A320, 2.3, 1200, "05:00", "07:00");
	LocalFlight Airbus_A320F3(&South_Peshawar, &South_Quetta, &Airbus_A320, 2.2, 1200, "09:00", "11:00");
	LocalFlight Airbus_A320F4(&South_Quetta, &South_Lahore, &Airbus_A320, 2.4, 1200, "13:00", "15:00");
	LocalFlight Airbus_A320F5(&South_Lahore, &North_Islamabad, &Airbus_A320, 2.22, 1200, "17:00", "19:00");


	D.addLocalFlight(&Airbus_A320F1);
	D.addLocalFlight(&Airbus_A320F2);
	D.addLocalFlight(&Airbus_A320F3);
	D.addLocalFlight(&Airbus_A320F4);
	D.addLocalFlight(&Airbus_A320F5);


	//South
	LocalFlight Embraer_E190F1(&South_Islamabad, &South_Karachi, &Embraer_E190, 2.55, 1200, "03:00", "05:00");
	LocalFlight Embraer_E190F2(&South_Karachi, &South_Peshawar, &Embraer_E190, 2.5, 1200, "07:00", "09:00");
	LocalFlight Embraer_E190F3(&South_Peshawar, &South_Quetta, &Embraer_E190, 2.3, 1200, "11:00", "13:00");
	LocalFlight Embraer_E190F4(&South_Quetta, &South_Lahore, &Embraer_E190, 2.2, 1200, "15:00", "17:00");
	LocalFlight Embraer_E190F5(&South_Lahore, &South_Islamabad, &Embraer_E190, 2.45, 1200, "19:00", "21:00");


	D.addLocalFlight(&Embraer_E190F1);
	D.addLocalFlight(&Embraer_E190F2);
	D.addLocalFlight(&Embraer_E190F3);
	D.addLocalFlight(&Embraer_E190F4);
	D.addLocalFlight(&Embraer_E190F5);

	LocalFlight Fokker_F27F1(&South_Islamabad, &North_Karachi, &Fokker_F27, 2.22, 1200, "03:00", "05:00");
	LocalFlight Fokker_F27F2(&North_Karachi, &North_Peshawar, &Fokker_F27, 2.23, 1200, "07:00", "9:00");
	LocalFlight Fokker_F27F3(&North_Peshawar, &North_Quetta, &Fokker_F27, 2.45, 1200, "11:00", "13:00");
	LocalFlight Fokker_F27F4(&North_Quetta, &North_Lahore, &Fokker_F27, 2.24, 1200, "15:00", "17:00");
	LocalFlight Fokker_F27F5(&North_Lahore, &South_Islamabad, &Fokker_F27, 2.3, 1200, "19:00", "21:00");


	D.addLocalFlight(&Fokker_F27F1);
	D.addLocalFlight(&Fokker_F27F2);
	D.addLocalFlight(&Fokker_F27F3);
	D.addLocalFlight(&Fokker_F27F4);
	D.addLocalFlight(&Fokker_F27F5);


	//lahore

	//North
	LocalFlight Boeing_767F1(&North_Lahore, &North_Karachi, &Boeing_767, 2.1, 1200, "03:00", "05:00");
	LocalFlight Boeing_767F2(&North_Karachi, &North_Peshawar, &Boeing_767, 2.12, 1200, "07:00", "09:00");
	LocalFlight Boeing_767F3(&North_Peshawar, &North_Quetta, &Boeing_767, 2.31, 1200, "11:00", "13:00");
	LocalFlight Boeing_767F4(&North_Quetta, &North_Islamabad, &Boeing_767, 2.45, 1200, "15:00", "17:00");
	LocalFlight Boeing_767F5(&North_Islamabad, &North_Lahore, &Boeing_767, 2.31, 1200, "19:00", "21:00");

	D.addLocalFlight(&Boeing_767F1);
	D.addLocalFlight(&Boeing_767F2);
	D.addLocalFlight(&Boeing_767F3);
	D.addLocalFlight(&Boeing_767F4);
	D.addLocalFlight(&Boeing_767F5);

	LocalFlight Airbus_A321F1(&North_Lahore, &South_Karachi, &Airbus_A321, 2.45, 1200, "01:00", "03:00");
	LocalFlight Airbus_A321F2(&South_Karachi, &South_Peshawar, &Airbus_A321, 2.21, 1200, "05:00", "07:00");
	LocalFlight Airbus_A321F3(&South_Peshawar, &South_Quetta, &Airbus_A321, 2.46, 1200, "09:00", "11:00");
	LocalFlight Airbus_A321F4(&South_Quetta, &South_Islamabad, &Airbus_A321, 2.32, 1200, "13:00", "15:00");
	LocalFlight Airbus_A321F5(&South_Islamabad, &North_Lahore, &Airbus_A321, 2.22, 1200, "17:00", "19:00");

	D.addLocalFlight(&Airbus_A321F1);
	D.addLocalFlight(&Airbus_A321F2);
	D.addLocalFlight(&Airbus_A321F3);
	D.addLocalFlight(&Airbus_A321F4);
	D.addLocalFlight(&Airbus_A321F5);
	//south
	LocalFlight Airbus_A330F1(&South_Lahore, &South_Karachi, &Airbus_A330, 2.2, 1200, "03:00", "05:00");
	LocalFlight Airbus_A330F2(&South_Karachi, &South_Peshawar, &Airbus_A330, 2.41, 1200, "07:00", "09:00");
	LocalFlight Airbus_A330F3(&South_Peshawar, &South_Quetta, &Airbus_A330, 2.44, 1200, "11:00", "13:00");
	LocalFlight Airbus_A330F4(&South_Quetta, &South_Islamabad, &Airbus_A330, 2.21, 1200, "15:00", "17:00");
	LocalFlight Airbus_A330F5(&South_Islamabad, &South_Lahore, &Airbus_A330, 2.1, 1200, "19:00", "21:00");

	D.addLocalFlight(&Airbus_A330F1);
	D.addLocalFlight(&Airbus_A330F2);
	D.addLocalFlight(&Airbus_A330F3);
	D.addLocalFlight(&Airbus_A330F4);
	D.addLocalFlight(&Airbus_A330F5);

	LocalFlight Boeing_757F1(&South_Lahore, &North_Karachi, &Boeing_757, 2.23, 1200, "03:00", "05:00");
	LocalFlight Boeing_757F2(&North_Karachi, &North_Peshawar, &Boeing_757, 2.32, 1200, "07:00", "09:00");
	LocalFlight Boeing_757F3(&North_Peshawar, &North_Quetta, &Boeing_757, 2.44, 1200, "11:00", "13:00");
	LocalFlight Boeing_757F4(&North_Quetta, &North_Islamabad, &Boeing_757, 2.34, 1200, "15:00", "17:00");
	LocalFlight Boeing_757F5(&North_Islamabad, &South_Lahore, &Boeing_757, 2.4, 1200, "19:00", "21:00");

	D.addLocalFlight(&Boeing_757F1);
	D.addLocalFlight(&Boeing_757F2);
	D.addLocalFlight(&Boeing_757F3);
	D.addLocalFlight(&Boeing_757F4);
	D.addLocalFlight(&Boeing_757F5);
	//Karachi

	//North
	LocalFlight Boeing_737_800F1(&North_Karachi, &North_Islamabad, &Boeing_737_800, 2.55, 1200, "03:00", "05:00");
	LocalFlight Boeing_737_800F2(&North_Islamabad, &North_Peshawar, &Boeing_737_800, 2.32, 1200, "07:00", "09:00");
	LocalFlight Boeing_737_800F3(&North_Peshawar, &North_Quetta, &Boeing_737_800, 2.3, 1200, "11:00", "13:00");
	LocalFlight Boeing_737_800F4(&North_Quetta, &North_Lahore, &Boeing_737_800, 2.45, 1200, "15:00", "17:00");
	LocalFlight Boeing_737_800F5(&North_Lahore, &North_Karachi, &Boeing_737_800, 2.1, 1200, "19:00", "21:00");

	D.addLocalFlight(&Boeing_737_800F1);
	D.addLocalFlight(&Boeing_737_800F2);
	D.addLocalFlight(&Boeing_737_800F3);
	D.addLocalFlight(&Boeing_737_800F4);
	D.addLocalFlight(&Boeing_737_800F5);

	LocalFlight Boeing_747_400F1(&North_Karachi, &South_Islamabad, &Boeing_747_400, 2.00, 1200, "01:00", "03:00");
	LocalFlight Boeing_747_400F2(&South_Islamabad, &South_Peshawar, &Boeing_747_400, 2.34, 1200, "05:00", "07:00");
	LocalFlight Boeing_747_400F3(&South_Peshawar, &South_Quetta, &Boeing_747_400, 2.43, 1200, "09:00", "11:00");
	LocalFlight Boeing_747_400F4(&South_Quetta, &South_Lahore, &Boeing_747_400, 2.22, 1200, "13:00", "15:00");
	LocalFlight Boeing_747_400F5(&South_Lahore, &North_Karachi, &Boeing_747_400, 2.14, 1200, "17:00", "19:00");

	D.addLocalFlight(&Boeing_747_400F1);
	D.addLocalFlight(&Boeing_747_400F2);
	D.addLocalFlight(&Boeing_747_400F3);
	D.addLocalFlight(&Boeing_747_400F4);
	D.addLocalFlight(&Boeing_747_400F5);
	//South
	LocalFlight Boeing_757_200F1(&South_Karachi, &South_Islamabad, &Boeing_757_200, 2.2, 1200, "03:00", "05:00");
	LocalFlight Boeing_757_200F2(&South_Islamabad, &South_Peshawar, &Boeing_757_200, 2.3, 1200, "07:00", "09:00");
	LocalFlight Boeing_757_200F3(&South_Peshawar, &South_Quetta, &Boeing_757_200, 2.5, 1200, "11:00", "13:00");
	LocalFlight Boeing_757_200F4(&South_Quetta, &South_Lahore, &Boeing_757_200, 2.45, 1200, "15:00", "17:00");
	LocalFlight Boeing_757_200F5(&South_Lahore, &South_Karachi, &Boeing_757_200, 2.31, 1200, "19:00", "21:00");


	D.addLocalFlight(&Boeing_757_200F1);
	D.addLocalFlight(&Boeing_757_200F2);
	D.addLocalFlight(&Boeing_757_200F3);
	D.addLocalFlight(&Boeing_757_200F4);
	D.addLocalFlight(&Boeing_757_200F5);

	LocalFlight Boeing_777_200F1(&South_Karachi, &North_Islamabad, &Boeing_777_200, 2.23, 1200, "03:00", "05:00");
	LocalFlight Boeing_777_200F2(&North_Islamabad, &North_Peshawar, &Boeing_777_200, 2.22, 1200, "07:00", "09:00");
	LocalFlight Boeing_777_200F3(&North_Peshawar, &North_Quetta, &Boeing_777_200, 2.45, 1200, "11:00", "13:00");
	LocalFlight Boeing_777_200F4(&North_Quetta, &North_Lahore, &Boeing_777_200, 2.4, 1200, "15:00", "17:00");
	LocalFlight Boeing_777_200F5(&North_Lahore, &South_Karachi, &Boeing_777_200, 2.5, 1200, "19:00", "21:00");

	D.addLocalFlight(&Boeing_777_200F1);
	D.addLocalFlight(&Boeing_777_200F2);
	D.addLocalFlight(&Boeing_777_200F3);
	D.addLocalFlight(&Boeing_777_200F4);
	D.addLocalFlight(&Boeing_777_200F5);
	//Peshawar

	//North
	LocalFlight Embraer_E195F1(&North_Peshawar, &North_Islamabad, &Embraer_E195, 2.43, 1200, "03:00", "05:00");
	LocalFlight Embraer_E195F2(&North_Islamabad, &North_Karachi, &Embraer_E195, 2.22, 1200, "07:00", "09:00");
	LocalFlight Embraer_E195F3(&North_Karachi, &North_Quetta, &Embraer_E195, 2.4, 1200, "11:00", "13:00");
	LocalFlight Embraer_E195F4(&North_Quetta, &North_Lahore, &Embraer_E195, 2.33, 1200, "15:00", "17:00");
	LocalFlight Embraer_E195F5(&North_Lahore, &North_Peshawar, &Embraer_E195, 2.55, 1200, "19:00", "21:00");

	D.addLocalFlight(&Embraer_E195F1);
	D.addLocalFlight(&Embraer_E195F2);
	D.addLocalFlight(&Embraer_E195F3);
	D.addLocalFlight(&Embraer_E195F4);
	D.addLocalFlight(&Embraer_E195F5);

	LocalFlight Antonov_An148F1(&North_Peshawar, &South_Islamabad, &Antonov_An148, 2.45, 1200, "01:00", "03:00");
	LocalFlight Antonov_An148F2(&South_Islamabad, &South_Karachi, &Antonov_An148, 2.3, 1200, "05:00", "07:00");
	LocalFlight Antonov_An148F3(&South_Karachi, &South_Quetta, &Antonov_An148, 2.2, 1200, "09:00", "11:00");
	LocalFlight Antonov_An148F4(&South_Quetta, &South_Lahore, &Antonov_An148, 2.12, 1200, "13:00", "15:00");
	LocalFlight Antonov_An148F5(&South_Lahore, &North_Peshawar, &Antonov_An148, 2.5, 1200, "17:00", "19:00");

	D.addLocalFlight(&Antonov_An148F1);
	D.addLocalFlight(&Antonov_An148F2);
	D.addLocalFlight(&Antonov_An148F3);
	D.addLocalFlight(&Antonov_An148F4);
	D.addLocalFlight(&Antonov_An148F5);

	//South
	LocalFlight Saab_2000F1(&South_Peshawar, &South_Karachi, &Saab_2000, 2.05, 1200, "03:00", "05:00");
	LocalFlight Saab_2000F2(&South_Karachi, &South_Islamabad, &Saab_2000, 2.07, 1200, "07:00", "09:00");
	LocalFlight Saab_2000F3(&South_Islamabad, &South_Quetta, &Saab_2000, 2.2, 1200, "11:00", "13:00");
	LocalFlight Saab_2000F4(&South_Quetta, &South_Lahore, &Saab_2000, 2.09, 1200, "15:00", "17:00");
	LocalFlight Saab_2000F5(&South_Lahore, &South_Peshawar, &Saab_2000, 2.08, 1200, "19:00", "21:00");

	D.addLocalFlight(&Saab_2000F1);
	D.addLocalFlight(&Saab_2000F2);
	D.addLocalFlight(&Saab_2000F3);
	D.addLocalFlight(&Saab_2000F4);
	D.addLocalFlight(&Saab_2000F5);

	LocalFlight ATR_72_500F1(&South_Peshawar, &North_Karachi, &ATR_72_500, 2.2, 1200, "03:00", "05:00");
	LocalFlight ATR_72_500F2(&North_Karachi, &North_Islamabad, &ATR_72_500, 2.4, 1200, "07:00", "09:00");
	LocalFlight ATR_72_500F3(&North_Islamabad, &North_Quetta, &ATR_72_500, 2.3, 1200, "11:00", "13:00");
	LocalFlight ATR_72_500F4(&North_Quetta, &North_Lahore, &ATR_72_500, 2.01, 1200, "15:00", "17:00");
	LocalFlight ATR_72_500F5(&North_Lahore, &South_Karachi, &ATR_72_500, 2.06, 1200, "19:00", "21:00");

	D.addLocalFlight(&ATR_72_500F1);
	D.addLocalFlight(&ATR_72_500F2);
	D.addLocalFlight(&ATR_72_500F3);
	D.addLocalFlight(&ATR_72_500F4);
	D.addLocalFlight(&ATR_72_500F5);
	//Quetta

	//North
	LocalFlight Boeing_727F1(&North_Quetta, &North_Islamabad, &Boeing_727, 2.2, 1200, "03:00", "05:00");
	LocalFlight Boeing_727F2(&North_Islamabad, &North_Peshawar, &Boeing_727, 2.03, 1200, "07:00", "09:00");
	LocalFlight Boeing_727F3(&North_Peshawar, &North_Lahore, &Boeing_727, 2.45, 1200, "11:00", "13:00");
	LocalFlight Boeing_727F4(&North_Lahore, &North_Karachi, &Boeing_727, 2.06, 1200, "15:00", "17:00");
	LocalFlight Boeing_727F5(&North_Karachi, &North_Quetta, &Boeing_727, 2.23, 1200, "19:00", "21:00");

	D.addLocalFlight(&Boeing_727F1);
	D.addLocalFlight(&Boeing_727F2);
	D.addLocalFlight(&Boeing_727F3);
	D.addLocalFlight(&Boeing_727F4);
	D.addLocalFlight(&Boeing_727F5);

	LocalFlight Boeing_750F1(&North_Quetta, &South_Islamabad, &Boeing_750, 2.54, 1200, "01:00", "03:00");
	LocalFlight Boeing_750F2(&South_Islamabad, &South_Peshawar, &Boeing_750, 2.2, 1200, "05:00", "07:00");
	LocalFlight Boeing_750F3(&South_Peshawar, &South_Lahore, &Boeing_750, 2.02, 1200, "09:00", "11:00");
	LocalFlight Boeing_750F4(&South_Lahore, &South_Karachi, &Boeing_750, 2.25, 1200, "13:00", "15:00");
	LocalFlight Boeing_750F5(&South_Karachi, &North_Quetta, &Boeing_750, 2.32, 1200, "17:00", "19:00");

	D.addLocalFlight(&Boeing_750F1);
	D.addLocalFlight(&Boeing_750F2);
	D.addLocalFlight(&Boeing_750F3);
	D.addLocalFlight(&Boeing_750F4);
	D.addLocalFlight(&Boeing_750F5);
	//South
	LocalFlight Bombardier_CRJ900F1(&South_Quetta, &South_Islamabad, &Bombardier_CRJ900, 2.06, 1200, "03:00", "05:00");
	LocalFlight Bombardier_CRJ900F2(&South_Islamabad, &South_Peshawar, &Bombardier_CRJ900, 2.22, 1200, "07:00", "09:00");
	LocalFlight Bombardier_CRJ900F3(&South_Peshawar, &South_Lahore, &Bombardier_CRJ900, 2.09, 1200, "11:00", "13:00");
	LocalFlight Bombardier_CRJ900F4(&South_Lahore, &South_Karachi, &Bombardier_CRJ900, 2.45, 1200, "15:00", "17:00");
	LocalFlight Bombardier_CRJ900F5(&South_Karachi, &South_Quetta, &Bombardier_CRJ900, 2.5, 1200, "19:00", "21:00");

	D.addLocalFlight(&Bombardier_CRJ900F1);
	D.addLocalFlight(&Bombardier_CRJ900F2);
	D.addLocalFlight(&Bombardier_CRJ900F3);
	D.addLocalFlight(&Bombardier_CRJ900F4);
	D.addLocalFlight(&Bombardier_CRJ900F5);

	LocalFlight Canadair_CL215F1(&South_Quetta, &North_Islamabad, &Canadair_CL215, 2.06, 1200, "03:00", "05:00");
	LocalFlight Canadair_CL215F2(&North_Islamabad, &North_Peshawar, &Canadair_CL215, 2.46, 1200, "07:00", "09:00");
	LocalFlight Canadair_CL215F3(&North_Peshawar, &North_Lahore, &Canadair_CL215, 2.22, 1200, "11:00", "13:00");
	LocalFlight Canadair_CL215F4(&North_Lahore, &North_Karachi, &Canadair_CL215, 2.45, 1200, "15:00", "17:00");
	LocalFlight Canadair_CL215F5(&North_Karachi, &South_Quetta, &Canadair_CL215, 2.09, 1200, "19:00", "21:00");

	D.addLocalFlight(&Canadair_CL215F1);
	D.addLocalFlight(&Canadair_CL215F2);
	D.addLocalFlight(&Canadair_CL215F3);
	D.addLocalFlight(&Canadair_CL215F4);
	D.addLocalFlight(&Canadair_CL215F5);
	//International flights 

	InternationalFlight Boeing_747F1(&North_Islamabad, &SaudiArabia, &Boeing_747, 2.78, 2501, "04:00", "07:00");
	InternationalFlight Airbus_A380F2(&North_Islamabad, &Yemen, &Airbus_A380, 2.94, 2686, "05:00", "08:00");
	InternationalFlight Boeing_787F3(&North_Islamabad, &Qatar, &Airbus_A380, 2.05, 1867, "06:00", "08:00");

	InternationalFlight Boeing_747F4(&North_Islamabad, &Oman, &Boeing_747, 2.08, 1896, "13:00", "15:00");
	InternationalFlight Airbus_A380F5(&North_Islamabad, &Bahrain, &Airbus_A380, 1.82, 1662, "17:00", "19:00");

	D.addIntlFlight(&Boeing_747F1);
	D.addIntlFlight(&Airbus_A380F2);
	D.addIntlFlight(&Boeing_787F3);
	D.addIntlFlight(&Boeing_747F4);
	D.addIntlFlight(&Airbus_A380F5);

	//2


	InternationalFlight Fokker_F28F1(&South_Islamabad, &Kuwait, &Fokker_F28, 2.31, 2108, "03:00", "05:00");
	InternationalFlight ATR_42F2(&South_Islamabad, &Iran, &ATR_42, 1.65, 1501, "04:00", "06:00");
	InternationalFlight ATR_72F3(&South_Islamabad, &China, &ATR_72, 3.6, 3284, "05:00", "08:00");

	InternationalFlight Fokker_F28F4(&South_Islamabad, &Turkey, &Fokker_F28, 3.76, 3240, "10:00", "14:00");
	InternationalFlight ATR_42F5(&South_Islamabad, &Malaysia, &ATR_42, 4.92, 4409, "11:00", "15:00");

	D.addIntlFlight(&Fokker_F28F1);
	D.addIntlFlight(&ATR_42F2);
	D.addIntlFlight(&ATR_72F3);
	D.addIntlFlight(&Fokker_F28F4);
	D.addIntlFlight(&ATR_42F5);

	//3 Lahore

	InternationalFlight McDonnell_Douglas_MD11F1(&North_Lahore, &Singapore, &McDonnell_Douglas_MD11, 5.33, 4859, "01:00", "06:00");
	InternationalFlight McDonnell_Douglas_MD90F2(&North_Lahore, &Thailand, &McDonnell_Douglas_MD90, 3.94, 3597, "02:00", "06:00");
	InternationalFlight Boeing_777F3(&North_Lahore, &Indonesia, &Boeing_777, 6.41, 5847, "03:00", "09:00");

	InternationalFlight McDonnell_Douglas_MD11F4(&North_Lahore, &India, &McDonnell_Douglas_MD11, 1.59, 1452, "15:00", "17:00");
	InternationalFlight McDonnell_Douglas_MD90F5(&North_Lahore, &Bangladesh, &McDonnell_Douglas_MD90, 2.42, 2205, "13:00", "15:00");

	D.addIntlFlight(&McDonnell_Douglas_MD11F1);
	D.addIntlFlight(&McDonnell_Douglas_MD90F2);
	D.addIntlFlight(&Boeing_777F3);
	D.addIntlFlight(&McDonnell_Douglas_MD11F4);
	D.addIntlFlight(&McDonnell_Douglas_MD90F5);

	//4


	InternationalFlight McDonnell_Douglas_DC10F1(&South_Lahore, &Nepal, &McDonnell_Douglas_DC10, 1.78, 1447, "03:00", "05:00");
	InternationalFlight McDonnell_Douglas_MD80F2(&South_Lahore, &Srilanka, &McDonnell_Douglas_MD80, 3.04, 2770, "02:00", "05:00");
	InternationalFlight Airbus_A340F3(&South_Lahore, &Egypt, &Airbus_A340, 4.13, 3765, "04:00", "08:00");

	InternationalFlight McDonnell_Douglas_DC10F4(&South_Lahore, &Morocco, &McDonnell_Douglas_DC10, 7.8, 7116, "10:00", "18:00");
	InternationalFlight McDonnell_Douglas_MD80F5(&South_Lahore, &Sudan, &McDonnell_Douglas_MD80, 4.89, 4457, "11:00", "15:00");

	D.addIntlFlight(&McDonnell_Douglas_DC10F1);
	D.addIntlFlight(&McDonnell_Douglas_MD80F2);
	D.addIntlFlight(&Airbus_A340F3);
	D.addIntlFlight(&McDonnell_Douglas_DC10F4);
	D.addIntlFlight(&McDonnell_Douglas_MD80F5);

	//5 karachi

	InternationalFlight Airbus_A300F1(&North_Karachi, &Russia, &Airbus_A300, 4.75, 4334, "05:00", "10:00");
	InternationalFlight Airbus_A310F2(&North_Karachi, &UK, &Airbus_A310, 6.81, 6211, "04:00", "11:00");
	InternationalFlight Airbus_A320neoF3(&North_Karachi, &Germany, &Airbus_A320neo, 6.5, 5930, "06:00", "12:00");

	InternationalFlight Airbus_A300F4(&North_Karachi, &France, &Airbus_A300, 5.66, 5160, "18:00", "24:00");
	InternationalFlight Airbus_A310F5(&North_Karachi, &Italy, &Airbus_A310, 3.42, 3478, "21:00", "24:00");

	D.addIntlFlight(&Airbus_A300F1);
	D.addIntlFlight(&Airbus_A310F2);
	D.addIntlFlight(&Airbus_A320neoF3);
	D.addIntlFlight(&Airbus_A300F4);
	D.addIntlFlight(&Airbus_A310F5);

	//6 
	InternationalFlight Airbus_A321neoF1(&South_Karachi, &Kuwait, &Airbus_A321neo, 2.31, 2108, "01:00", "03:00");
	InternationalFlight Airbus_A330_200F2(&South_Karachi, &Iran, &Airbus_A330_200, 1.65, 1501, "02:00", "04:00");
	InternationalFlight Airbus_A350_900F3(&South_Karachi, &China, &Airbus_A350_900, 3.6, 3284, "03:00", "07:00");

	InternationalFlight Airbus_A321neoF4(&South_Karachi, &Turkey, &Airbus_A321neo, 3.55, 3240, "08:00", "12:00");
	InternationalFlight Airbus_A330_200F5(&South_Karachi, &Malaysia, &Airbus_A330_200, 4.92, 4409, "09:00", "14:00");

	D.addIntlFlight(&Airbus_A321neoF1);
	D.addIntlFlight(&Airbus_A330_200F2);
	D.addIntlFlight(&Airbus_A350_900F3);
	D.addIntlFlight(&Airbus_A321neoF4);
	D.addIntlFlight(&Airbus_A330_200F5);

	//7 Peshawar

	InternationalFlight Antonov_An158F1(&North_Peshawar, &SaudiArabia, &Antonov_An158, 2.74, 2501, "4:AM", "7:AM");
	InternationalFlight Ilyushin_Il76F2(&North_Peshawar, &Yemen, &Ilyushin_Il76, 2.94, 2686, "5:AM", "8:AM");
	InternationalFlight Tupolev_Tu154F3(&North_Peshawar, &Qatar, &Tupolev_Tu154, 2.05, 1867, "6:AM", "8:AM");

	InternationalFlight Antonov_An158F4(&North_Peshawar, &Oman, &Antonov_An158, 2.08, 1896, "13:PM", "15:PM");
	InternationalFlight Airbus_A330_200F55(&North_Peshawar, &Bahrain, &Airbus_A330_200, 1.82, 1662, "17:AM", "19:PM");

	D.addIntlFlight(&Antonov_An158F1);
	D.addIntlFlight(&Ilyushin_Il76F2);
	D.addIntlFlight(&Tupolev_Tu154F3);
	D.addIntlFlight(&Antonov_An158F4);
	D.addIntlFlight(&Airbus_A330_200F55);

	//8

	InternationalFlight Antonov_An72F1(&South_Peshawar, &Nepal, &Antonov_An72, 1.59, 1447, "01:00", "03:00");
	InternationalFlight Yakovlev_Yak40F2(&South_Peshawar, &Srilanka, &Yakovlev_Yak40, 3.04, 2770, "02:00", "05:00");
	InternationalFlight Let_L410F3(&South_Peshawar, &Egypt, &Let_L410, 4.13, 3765, "03:00", "07:00");

	InternationalFlight Antonov_An72F4(&South_Peshawar, &Morocco, &Antonov_An72, 7.8, 7116, "08:00", "16:00");
	InternationalFlight Yakovlev_Yak40F5(&South_Peshawar, &Sudan, &Yakovlev_Yak40, 4.89, 4457, "11:00", "16:00");

	D.addIntlFlight(&Antonov_An72F1);
	D.addIntlFlight(&Yakovlev_Yak40F2);
	D.addIntlFlight(&Let_L410F3);
	D.addIntlFlight(&Antonov_An72F4);
	D.addIntlFlight(&Yakovlev_Yak40F5);

	//9 Quetta 

	InternationalFlight McDonnell_Douglas_DC11F1(&North_Quetta, &Russia, &McDonnell_Douglas_DC11, 4.75, 4334, "00:00", "05:00");
	InternationalFlight McDonnell_Douglas_MD11F2(&North_Quetta, &UK, &McDonnell_Douglas_MD11, 6.81, 6211, "01:00", "08:00");
	InternationalFlight Lockheed_L1011F3(&North_Quetta, &Germany, &Lockheed_L1011, 6.5, 5930, "02:00", "09:00");

	InternationalFlight McDonnell_Douglas_DC11F4(&North_Quetta, &France, &McDonnell_Douglas_DC11, 5.66, 5160, "13:00", "19:00");
	InternationalFlight McDonnell_Douglas_MD11F5(&North_Quetta, &Italy, &McDonnell_Douglas_MD11, 3.42, 3478, "18:00", "21:00");

	D.addIntlFlight(&McDonnell_Douglas_DC11F1);
	D.addIntlFlight(&McDonnell_Douglas_MD11F2);
	D.addIntlFlight(&Lockheed_L1011F3);
	D.addIntlFlight(&McDonnell_Douglas_DC11F4);
	D.addIntlFlight(&McDonnell_Douglas_MD11F5);

	//10

	InternationalFlight Canadair_CL415F1(&South_Quetta, &Singapore, &Canadair_CL415, 5.33, 4859, "05:00", "10:00");
	InternationalFlight Antonov_An26F2(&South_Quetta, &Thailand, &Antonov_An26, 3.94, 3597, "06:00", "10:00");
	InternationalFlight Antonov_An74F3(&South_Quetta, &Indonesia, &Antonov_An74, 6.41, 5847, "07:00", "13:00");

	InternationalFlight Canadair_CL415F4(&South_Quetta, &India, &Canadair_CL415, 1.59, 1452, "18:00", "20:00");
	InternationalFlight Antonov_An26F5(&South_Quetta, &Bangladesh, &Antonov_An26, 2.42, 2205, "17:00", "19:00");

	D.addIntlFlight(&Canadair_CL415F1);
	D.addIntlFlight(&Antonov_An26F2);
	D.addIntlFlight(&Antonov_An74F3);
	D.addIntlFlight(&Canadair_CL415F4);
	D.addIntlFlight(&Antonov_An26F5);


	Menu M;
	M.AddAllFlights(&D);
	D.AddCountry(&Pakistan);
	M.DisplayMainMenu();

	return 0;
}