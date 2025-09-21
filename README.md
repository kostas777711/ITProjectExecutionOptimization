# ITProjectExecutionOptimization
Algorithm that optimizes the execution of an IT project

The Diagram below presents on a high level the approach of the inputs and the outputs as a system for the 2nd phase.
<img width="975" height="402" alt="εικόνα" src="https://github.com/user-attachments/assets/45d42d5c-ff1a-4c79-816a-0c62622f3743" />

To implement the above system a custom algorithm was developed in Eclipse programming IDE in C programming language. Its high-level description can be seen on the piece of pseudocode below (presented in detail in the Appendix):
for ( i=1; i<I; i++) //initialize Activities durations
{
     di=0; 
}
for ( p=1; p<P; p++)// looking into the workdays, starting 1st next
{
          for ( k=1; k<K; k++)//checking resources one by one
          {
                       if ( ak,p==1 )// if resource is needed 
                       {
                            for ( j=1; j<J; j++)// checking the skill availability
                            {
                                  if (rk,j ==1 ) && (si,j > 0 )  // if resource has the skill and if skill is needed
                                   {
                                      di++;      // book resource, add manday/period of work for this task
                                      si,j--;      // reduce required effort from work to be done
                                      break;
                                    }
                            }
                        }

           }
}

Initially, we do initialize to zero the duration of the individual tasks/activities of the project. Consequently, we do scan in a sequential manner every next workday by resource skill type. If resource is needed, we double check if this resource has the needed skillset. If it has the needed skill then we do book the resource, after that the search continues. If the skill needed is not possessed by the specific resource, then we continue the search.
