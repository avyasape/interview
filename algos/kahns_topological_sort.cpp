/* 
   Topo Sort on DAG 
*/

void kahns(vector<vector<int>> adjList) {
  int n = adjList.size();
  //calculate indegree of nodes
  vector<int> inDeg(n);
  for (int i = 0; i < n; ++i) {
    for (auto n: adjList[i])
      inDeg[n]++;
  }
  vector<int> topoOrder;
  queue<int> q;
  for (int i = 0; i < n; ++i)
  {
    if (inDeg[i] == 0)
      q.push(i);
  }
  
  while (!q.empty()) {
    int n = q.front();
    topo.push(n);
    for (auto c: adjList[n]) {
      if (--inDeg[c] == 0)
        q.push(c);
    }
  }
  if (topoOrder.size() == n)
    return topoOrder;
  else
    //cannot visit so cycle
}
