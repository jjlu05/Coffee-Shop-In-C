int currentTime = 0;
    while (currentTime < totalTime) {//conditional which checks to see if the current time step has hit the total time allotted for the simulation or not
    //This conditional must be '<'. '<=' will result in error. It might be because I have initialized currentTime to 0 and not 1.
        for (int i = 0; i < baristas.size(); i++) {//for eveery barista            
            if (currentTime >= (baristas[i].getStart() + baristas[i].getDuration())) //if a barista has finished their current task since theyve had more than enough time to complete it based off the order's duration
                    // Barista has finished their task
               baristas[i].setBusy(0);//set the barista to not busy
               baristas[i].setStart(0);//reset the current task_start
               baristas[i].setDuration(0);//resets the current task_duration
            
            

            //assign new orders to baristas from the front of the queue
            if (baristas[i].getBusy() == 0) {//conditional, to check if barista is not busy
                auto frontOrder = orders.peekFrontOrder();//create this auto variable to avoid having to write orders.peekFrontOrder()
                if (currentTime >= frontOrder->getArrival()) {//if current time is greater than arrival time of the front order, which is accessed by using an arrow, since frontOrder is a pointer to memory on heap
                    //modify barista values based on the front order
                    baristas[i].setBusy(1);//barista is now busy
                    baristas[i].setStart(currentTime);
                    baristas[i].setDuration(frontOrder->getCook());//set task_duration to the cook time of the order

                    frontOrder->setStart(currentTime);
                    frontOrder->setWait(currentTime - frontOrder->getArrival());//set 
                    
                    orders.removeFrontOrder();//removes the front order from the queue with all the orders
                    completedOrders.push_back(*frontOrder);//adds a completed order to the end of the completedOrders vector
                }
            }

            //if barista is not busy, increase free time
            if (baristas[i].getBusy() == 0) {
                baristas[i].increaseFree();

            }
        }

        //increment time step
        ++currentTime;
    }