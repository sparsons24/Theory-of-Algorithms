IMPLEMENTATION OF THE 0/1 KNAPSACK PROBLEM
Sarah Parsons
Wake Forest University

INTRODUCTION
Dynamic programming, motivated by recursion and known for its modified brute force approach, is a strategic method to solving optimization problems that require solutioning over all sets of all sizes at most one time. Often, the structure of the problem limits the number of subsets needed to be solved, and thus, introduces the privilege of only solving each subset once. Many well-known problems have been solved using dynamic programming. Problems that can be represented by a directed acyclic graph with sorted vertices or a grid with symbolic edges and weights are often prime candidates for the use of dynamic programming. One such problem is the famous 0/1 Knapsack Problem [1] – how can one determine which weighted multivalued items to include in a knapsack given a capacity constraint and a desire to achieve a maximum profit of values? After studying the mechanics of dynamic programming, I have developed a program using C++ to implement the solution of the knapsack problem. Furthermore, I have conducted analysis on the complexity of the proposed algorithm and the cost of each component of my solution. 

DYNAMIC PROGRAMMING & THE KNAPSACK PROBLEM
Algorithms for dynamic programming are most commonly applied to optimization challenges. With such a broad use case, dynamic programming has become a popular strategy among many academic groups. In Jones and Pevzner’s Bioinformatic Algorithms, dynamic programming has been adopted by biologists in an effort to conduct gene sequencing and DNA matching [2]. Discoveries of the cystic fibrosis gene and links between cancerous genes and normal genes are a few examples of how biologists have employed dynamic programming to study DNA sequences. Likewise, tackling the Edit Distance problem or alignment problems, such as Global Sequence Alignment or Local Sequence Alignment, using dynamic programming has led biologists to better understand DNA mutations and their implications [2]. Furthermore, optimizing “resource allocation”, as illustrated in the process of solving the knapsack problem using dynamic programming, can have profound impacts on many industries as well [3]. The focus of this paper will be on solving the knapsack problem.
Consider the dilemma of filling a knapsack with the maximum value possible by choosing from a set of items, each possessing a value and a weight, without exceeding the weight limit of the bag. Dating back to the late 19th century, Tobias Dantzig is cited as the originator of the knapsack problem [3]. As an age-old problem, the concept has become an interdisciplinary practice with applications ranging from finance to computer science to sports [3]. Additionally, there have been numerous variations of the problem, including the challenge of having multiple knapsacks, or the goal of achieving the maximum profit and a maximum number of items while satisfying specific stipulations of each item [3]. The most popular adaptation is described as the “0/1 knapsack problem”, in which each item can be selected as a whole at most one time and cannot be partitioned to better fit the bag [3]. There are several approaches to solve, but as we will see, to achieve optimal efficiency, exercising dynamic programming is one of the better methods.  


ALGORITHM
	Upon studying the benefits of dynamic programming and its applications, I applied my understanding to the knapsack problem and designed a solution. Key data structures in my algorithm include a 2-D array of solutions, Knap; three vector lists in which the weights, values, and items are stored; and a struct, Point, consisting of an x, y, and z component to keep track of the path, (x,y), to the maximum solution and an indicator, (z), of whether or not an item is included in the knapsack. The computation process is completed for every possible combination of capacity, C, and number of items, n. The final combination serves as the desired maximum solution of the knapsack problem. Each calculation is stored in Knap and used in later calculations for unsolved cells in the array. A second 2-D array, Path, is used to store the path and indicator, or x, y, and z-coordinates of each computation needed to reach the maximum solution. From both arrays, the X value of 0 or 1 is determined based on the value of z for each coordinate in the path to the maximum value.  
As described above, the Knap and Path arrays display the maximum values and the coordinates for which the values are computed. See below for an example output of the program, including these arrays, the maximum value (last column, bottom row), path of coordinates to the maximum value, and the X values for each corresponding item.

  
To implement the algorithm, after building the arrays, vector lists, and struct, the first row and column of the Knap and Point arrays were initialized to 0 and (0,0), respectively, as it can be assumed that with 0 items or 0 capacity, the maximum value of the items in the knapsack will be 0 and there are no prior iterations to check, so the coordinate path is defaulted to (0,0). This step is necessary to highlight due its contribution to the overall complexity, as discussed in the next section. For the core of the process, the remaining cells in the Knap array are filled using the following formula:

Knap(C,n)=max{K0 = Knap(w,j-1), K1 = vj+Knap(w-wj,j-1)} for C={w_1,w_2,...,w_C}, n={j_1,j_2,...,j_n}

As depicted in the above formula, the solution for each cell in the Knap array is determined by comparing the value of the cell in the prior column on the current row to the (value at the cell in the prior column at the row of the (current row minus the weight at the index of the prior column) plus the value element at the index of the current row). In future explanations, I will refer to each of these values as K0 and K1, respectively. 
For each row from the first to the last (C), and for each column from the first to the last (n), if K0 is less than K1, then K1 will be stored in the cell of the Knap array. In the Path array, for each row from the first to the last (C), for each column from the first to the last (n), assign the x component of the cell to the current column number minus the weight at the index of the current row (w-wj). Set the y component to the number of the current row minus 1 (j-1). Finally, set the z component to 1. Extractions of pseudocode for the core steps in the algorithm are below. To see the actual code, refer to the Appendix for parts I, II, and III.

I.	for all rows, k, from 1 to Capacity {
		for all columns, h, from 1 to # of weights {
if value of (row k, column h-1) < value of (row k–weights[h], column h-1) and (row k–weights[h]) > -1 {
assign value of (values[h] + value of (row k–weights[h], column h-1)) to (k,h) in Knap array
assign value of (row k–weights[h]) to x component of (k,h) in Path array
assign value of (h-1) to y component of (k,h) in Path
assign value of 1 to z component of (k,h) in Path } } }

Otherwise, if  K0 is greater than K1, then K0 will be stored in that cell of the Knap array. The x component of this position in the Path array will be set to the number of the current row and the y component will be set to the number of the prior column. z will be set to 0.

II.		      else {
assign value of (row k, column h-1)to (k,h) in Knap
assign k to x component of (k,h) in Path 
assign (h-1) to y component of (k,h) in Path
assign 0 to z component of (k,h) in Path }

Finally, after filling in both the Knap and Path arrays, the values are output to the screen and the maximum value is extracted from the last cell in the Knap grid (far right column, bottom row). With the arrays completed, the path to the maximum solution can now be determined. To do so, a recursive while loop was built to backtrack through the Path array from the location of the maximum value to (0,0), and to output each set of coordinates needed to compute the value at each location. 

III. 	assign s to x-coordinate of the location of the maximum value
	assign p to y-coordinate of the location of the maximum value
	while (s is not equal to 0 and p is not equal to 0) {
		print out (x-coordinate of Path[s][p], y-coordinate of Path[s][p])
		set s to x-coordinate of Path[s][p] and p to y-coordinate of Path[s][p] }	  

Similarly, the X values for each cell in the path can be determined once both arrays have been filled in. As seen in the pseudocode above in section III for the x- and y-coordinates, the z component of each set of coordinates can be retrieved from the Path array in the same manner. It is important to note that by backtracking through the array, the X values are retrieved in reverse order of the evaluation of each item, and thus, the 0/1 indicator for each item is output first for the items at the end of the items list.
Rather than adopt a recursive algorithm to find the maximum value of a given set of weighted items, I instead chose to use a 2-D array to store each maximum value computation as I traversed a grid plotting capacity against the number of items. By recording every calculation in an array, each problem was solved only one time and could be referenced in later calculations, if necessary. The crux of dynamic programming is the benefit of only having to solve each problem once. On the other hand, there is still a need to solve every sub-problem before finding the final solution to the general problem. Despite this downside, the gain in efficiency compared to using recursion is noteworthy and lends support to the use of dynamic programming for optimization challenges, such as the knapsack problem.  

ANALYSIS
	When studying algorithms, it is imperative to consider the complexity of different metrics, such as time and space. For the Knapsack Problem, the requirement to visit every cell in the Knap array entails completing n * C steps. Thus, the complexity could be considered as O(|n||C|). Unfortunately, despite its appearance as polynomial in nature, the inputs n and C are integers and so, the size of each input is lg(C) and lg(n). Consequently, the complexity becomes O\left(2^{lg\left(n\right)}2^{lg\left(C\right)}\right), and therefore, potentially requires exponential time. This makes the knapsack problem NP-complete, which weakens support for solving with dynamic programming. In an effort to slightly reduce the complexity of my algorithm, I initialized the first row and first column of my 2-D arrays to be 0 and (0,0), respectively. By doing so, I eliminated the need to compute the values of all cells in the first row (n) and in the first column (C). Although this group of cells is a small portion of the population, it is necessary to point out that the total processing time will be reduced as a result of this manual manipulation of the data. Also, consider that not only do we care about the maximum value, we are also interested in determining which items are included in the knapsack. The steps needed to output the maximum path and 0/1 indicator for each location in the maximum path are part of a recursive function. As a result, the complexity of this recursive loop requires 2^n for all n items. Overall, the time complexity of my algorithm is NP-complete due to the exponential nature of traversing the arrays and determining the 0/1 indicators of each item. Although dynamic programming is a well-known, popular method for optimization problems, it is critical to understand the stakes, and often, high cost associated with the algorithm, as shown for the knapsack problem.  

MEASUREMENTS
	To better understand the performance and efficiency of my algorithm, I gathered data for several test scenarios in which I altered C, the weights, values, and item numbers. To test, I recorded the processing time for multiple example combinations of C and n. See Table 1 for a list of computation times for each test case. I computed the average time TS of the algorithm times, after removing any outliers from my set of times. Due to the high processing times for the first and last runs of my cases, I decided to exclude these times in order to have a more wholistic average of the total computation time.

Number of items	Capacity	Weights	Values	Ts (s)	Average Ts(s)

4	8	{1,2,3,4}	{2,4,6,8}	0.686
{0.703
0.641
0.633
0.637
0.613
0.655
0.736}
0.663

4	10	{1,3,5,7}	{2,4,6,8}	0.527
{0.597
0.621
0.583
0.608
0.580
0.557
0.617}
0.586

5	20	{2,4,6,8,10}	{2,4,6,8,10}	0.597
{0.606
0.601
0.540
0.548
0.607
0.634
0.637}
0.596

5	100	{20,20,20,25,25}	{10,15,20,25,30}	0.581
{0.571
0.611
0.560
0.602
0.584
0.616
0.567}
0.587

10	10	{1,1,1,1,1,1,1,1,1,1}	{1,2,3,4,5,6,7,8,9,10}	0.633
{0.584
0.599
0.584
0.581
0.641
0.660
0.573}
0.607

Table 1: Computation times for a subset of knapsack problems. Note that computations were completed on an X1 Carbon Lenovo machine.

As shown in the table, the average computation times for my algorithm are relatively the same, ~0.6 seconds, for each of my test cases. Given the complexity of the algorithm as NP-complete, it is shown here that there are cases where the knapsack problem can be solved relatively fast. However, this may not be the case for all scenarios, particularly those with a high capacity and a large number of items. Unfortunately, I was not able to test for increasingly complex cases, as I could not construct test cases with a relatively large number of items. Despite this fault, it is clear from the complexity that the cost of computing each step for significant-sized knapsacks with numerous items could become unruly.  

CONCLUSION
	In summary, using dynamic programming I implemented a solution for the knapsack problem by leveraging a bottom-up approach with an array structure. As a result of the structure of my problem, I was able to employ two 2-D arrays to store previously computed solutions that I referenced for later calculations. With the constraint of considering only the prior number of items for a capacity versus the previous capacity with a newly added weight, I was able to avoid using recursion and thus, improve the efficiency of my program. As with all dynamic programming solutions, each computation was only solved once and after solving every cell in both arrays, I arrived at the final maximum solution. Despite having a possible complexity of exponential time, for cases with double-digit capacities and double-digit weights, my algorithm was able to solve the knapsack problem in a fraction of a second. I acknowledge that data for more complex test cases are important to fully understand the significance of the complexity of the problem. For such cases, I would argue that dynamic programming is not the best method to solve due to the problem being NP-complete. However, given the limitations of testing such cases, I can confidently confirm the efficiency of using this algorithm for less complex knapsack examples, as shown in my analysis, and I consider dynamic programming to be one of the better strategies. By employing dynamic programming to solve the knapsack problem, the process was iterative and clean, lending itself to a simplistic form of brute force that evoked beauty through its final step. 

 
REFERENCES
[1] 0-1 Knapsack Problem | DP-10. (2018, September 28). Retrieved October, 2018, from https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ 
 [2] Jones, N. C., & Pevzner, P. (2014). Introduction to Bioinformatics Algorithms. Cambridge: MIT Press.
[3] Knapsack problem. (2018, October 03). Retrieved October, 2018, from https://en.wikipedia.org/wiki/Knapsack_problem

 
APPENDIX
	
for (int k = 1; k < Capacity; k++) {
    for (int h = 1; h < weights.size(); h++) {
        if (k - weights[h] > -1 && knap[k][h - 1] < (values[h] + knap[k - weights[h]][h - 1])) {
            knap[k][h] = values[h] + knap[k - weights[h]][h - 1];
            Path[k][h].x = (k - weights[h]);
            Path[k][h].y = h - 1;
            Path[k][h].z = 1;
}


II.
else {
    knap[k][h] = knap[k][h - 1];
    Path[k][h].x = k;
    Path[k][h].y = h - 1;
    Path[k][h].z = 0;
    cout << knap[k][h];
}


III.
cout << "Maximum Path: (" << Capacity - 1 << "," << weights.size()-1 << ") << (" << Path[Capacity-1][weights.size()-1].x << "," << Path[Capacity-1][weights.size()-1].y << ")";

int s = Path[Capacity-1][weights.size()-1].x;
int p = Path[Capacity-1][weights.size()-1].y;
while(s != 0 && p !=0){
    cout << " << (" << Path[s][p].x << "," << Path[s][p].y << ")";
    s = Path[s][p].x;
    p = Path[s][p].y;
}

