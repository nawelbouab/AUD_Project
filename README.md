# How to run the AUD project ? 

1. Install Docker
2. Go on the terminal and where the project is on your computer
3. If you want to run the BFS algorithm, you have to write this in the command line : 
   `docker build . -t graphsearch && docker run -it graphsearch --bfs ……`. Instead of `…` you have to put the graph you want as input.
   For example : `docker build . -t graphsearch && docker run -it graphsearch --ffs 1-2,1-3,1-5,3-6,3-5,6-6,5-4,2-5,4-2`
4. If you want to run the DFS algorithm, you have to write this in the command line :
   `docker build . -t graphsearch && docker run -it graphsearch --dfs ……`. Instead of `…` you have to put the graph you want as input.
   For example : `docker build . -t graphsearch && docker run -it graphsearch --dfs 1-2,1-3,1-5,3-6,3-5,6-6,5-4,2-5,4-2`
5. Press enter and then you have the output. 