Maximum Subarray problem - solved using KADANE'S ALGORITHM
here in kadane's algorithm,
max= INT_MIN; //smallest possible no. 
sum=0; // sum taken to add elements of the list 

Approach :
1. if max< sum -> max= sum
2. if sum<0 at any point of time -. initialize sum to zero thereby cancelling the array till now and starting a new subarray 
3. in this way we get max sum from longest subarray 
