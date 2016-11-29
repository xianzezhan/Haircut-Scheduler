# Haircut-Scheduler
Haircut Scheduler
I. File list
------------
main.cpp            main driver for the project
scheduler.h       scheduler for adding appointments and listing appointments
README

II. Design
----------
This project is designed as a simple haricut scheduler by Xianze Zhan.
It's implemented in C++.
It is designed for a hairdresser who needs to keep track of his	or her haircut appointments.
Also, I assume the hairdresser works from 9am-9pm. He will accept the last appointment at 9pm. No matter it is haircut
or Shampoo&Haircut. Anytime schedule earlier than 9am or later than 9pm is invalid.

II. Command Line Input
----------------------
This program takes 5 types of input(all in lowercase):
1.  help                      Print out help info for running the program
2.  list                      Print out all scheduled appointments in time order.
3.  haircut/h $time           Schedule a haircut appointment at your input time. This appointment lasts 30 mins.
                              Time is in 3 or 4 digits decimal number format.
                              For example: 900 means 9am and 2300 means 11pm.
4.  shampoo&haircut/sh $time  Schedule a shampoo&haircut appointment at your input time. This appointment lasts 1 hour.
5.  exit                      Exit the program and delete data.


III. Test run logs
------------------
log1
-----
Please enter your command. Enter help for command info.
help
You may enter list, haircut/h [time], shampoo&haircut/sh [time], exit. Please use lower case only.
Example: sh 1300 means schedule a shampoo&haircut at 13:00.
Please enter your command. Enter help for command info
sh 900
adding shampoo & haircut to time: 900
haircut 1000
adding haircut to time: 1000
haircut 1015
Timeslot is not available, please re schedule.
haircut 1030
adding haircut to time: 1030
shampoo&haircut 1400
adding shampoo & haircut to time: 1400
haircut 1430
Timeslot is not available, please re schedule.
haircut 1500
adding haircut to time: 1500
aaas
Invalid Input. You may enter list, haircut [time], shampoo&haircut [time], exit. Please use lower case only.
Please enter your command.
h 1800
adding haircut to time: 1800
list
Appointment 1: Shampoo & Haircut at 900
Appointment 2: Haircut at 1000
Appointment 3: Haircut at 1030
Appointment 4: Shampoo & Haircut at 1400
Appointment 5: Haircut at 1500
Appointment 6: Haircut at 1800
Finish Printing all schedules.
exit

Process finished with exit code 0
----------

log2
----
Please enter your command. Enter help for command info.
list
Finish Printing all schedules.
help
You may enter list, haircut/h [time], shampoo&haircut/sh [time], exit. Please use lower case only.
Example: sh 1300 means schedule a shampoo&haircut at 13:00.
Please enter your command. Enter help for command info
sh 0800
Timeslot is not available, please re schedule.
sh 2000
adding shampoo & haircut to time: 2000
h 2100
adding haircut to time: 2100
h 1200
adding haircut to time: 1200
sh 1300
adding shampoo & haircut to time: 1300
h 2200
Timeslot is not available, please re schedule.
list
Appointment 1: Haircut at 1200
Appointment 2: Shampoo & Haircut at 1300
Appointment 3: Shampoo & Haircut at 2000
Appointment 4: Haircut at 2100
Finish Printing all schedules.

