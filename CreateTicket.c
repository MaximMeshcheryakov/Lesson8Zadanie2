CreateTicket()
{
	/* Flights */

	web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_ex(
		"ParamName=OFlight",
    	"LB=name=\"outboundFlight\" value=\"",
    	"RB=\"",
    	"Ordinal=all",
    	"NotFound=Warning",
			LAST);
	
	
	web_reg_save_param_ex(
		"ParamName=PriceTickets",
    	"LB=td align=\"center\">$ ",
    	"RB=<\/TD>",
    	"Ordinal=all",
    	"NotFound=Warning",
		LAST);
	
	
	/* Continue 1 */
	
	web_submit_data("reservations.pl", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartureCity}", ENDITEM, 
		"Name=departDate", "Value={DateOut}", ENDITEM, 
		"Name=arrive", "Value={ArrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={DateTo}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	lr_output_message("Price 1= %d",atoi(lr_eval_string("{PriceTickets_1}")));
	lr_output_message("Price 2= %d",atoi(lr_eval_string("{PriceTickets_2}")));
	lr_output_message("Price 3= %d",atoi(lr_eval_string("{PriceTickets_3}")));
	lr_output_message("Price 4= %d",atoi(lr_eval_string("{PriceTickets_4}")));
	
	
	ticket[1]=atoi(lr_eval_string("{PriceTickets_1}"));
	ticket[2]=atoi(lr_eval_string("{PriceTickets_2}"));
	ticket[3]=atoi(lr_eval_string("{PriceTickets_3}"));
	ticket[4]=atoi(lr_eval_string("{PriceTickets_4}"));
	
	lr_output_message("ticket1 = %d",ticket[1]);
	lr_output_message("ticket2 = %d",ticket[2]);
	lr_output_message("ticket3 = %d",ticket[3]);
	lr_output_message("ticket4 = %d",ticket[4]);
	
	flight[1]=lr_eval_string("{OFlight_1}");
	flight[2]=lr_eval_string("{OFlight_2}");
	flight[3]=lr_eval_string("{OFlight_3}");
	flight[4]=lr_eval_string("{OFlight_4}");
	
	lr_output_message("OFlight1 = %s",flight[1]);
	lr_output_message("OFlight2 = %s",flight[2]);
	lr_output_message("OFlight3 = %s",flight[3]);
	lr_output_message("OFlight4 = %s",flight[4]);
	
	for(i;i<=4;i++){
		if(ticket[i]%2==0){
			trueticket[k++] = flight[i];
			j++;
		}
	}
	
	if(j==0){
		lr_output_message("Билета нет");
	} else{
	
	lr_output_message("Билет есть");
	
	i = 1;
	for(i;i<k;i++){
		lr_output_message("True Ticket = %s",trueticket[i]);
	}

	srand(time(NULL));
  	randomT = rand() % j + 1;
  	lr_save_string(trueticket[randomT],"true");
 	lr_output_message("Рандомный элемент = %d",randomT);
 	lr_output_message("Выбран этот билет = %s",trueticket[randomT]);
	
	web_submit_data("reservations.pl_2", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={true}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=reserveFlights.x", "Value=71", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);
	

	/* Continue 3 */
	
	web_submit_data("reservations.pl_3", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={TypeSeat}", ENDITEM, 
		"Name=seatPref", "Value={PrefSeat}", ENDITEM, 
		"Name=outboundFlight", "Value={true}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=39", ENDITEM, 
		"Name=buyFlights.y", "Value=12", ENDITEM, 
		LAST);

	}
	return 0;
}
