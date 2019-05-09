# Coding_Challenge
Parking Lot System
The code is divided into functions.
Main has 3 modules Admin, Operator and Customer
These are tasks which are done in this code

# Admin Console: 
The admin (only one admin) accesses this portal without password (for
simplicity) and can do the following:

a. Add/Delete operators: each operator has a user name and password, and list of parking
lot IDs the operator has access to.

b. Add/Delete parking lot: Each parking lot have a number of parking spaces and per hour
rate.

c. List all available operators with their usernames/pass/parking lot IDs.

d. List all parking lot IDs/number of parking spaces/per hour rate.

e. Save/Load operators and parking lots information to the file system.

# 2. Operator Console: 
The operator is asked first to enter his/her username and pass. If login is
successful:

a. The operator can query total number of parking slots in a specific parking lot, with the
current number of free and busy ones.

b. The operator can query total amount of revenue (See Customer Console for details on
revenue) for each parking lot and for all parking lots under his custody.

c. The operator can find the parking lot ID at which a certain car (by plate number) is
located.

# 3. Customer Console: 
A customer can login with his unique car plate number (this has to be exactly
five digits’ integer, e.g. can be 00156) and once in, a customer can do the following:

a. Park his car in a specific parking lot. The customer can park at only one parking lot at any
given time.

b. Drive away. The customer is asked to enter the number of hours he has been in the
parking at this stage. Parking lot revenue is incremented here.
