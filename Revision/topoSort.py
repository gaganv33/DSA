graph = {
   '5' : ['2', '0'],
   '4' : ['0', '1'],
   '2' : ['3'],
   '3' : [],
   '1' : [],
   '0' : []
}

queue = []
visited = []

def dfsTraversal(node):
   visited.append(node)

   for x in graph[node]:
      if x not in visited:
         dfsTraversal(x)
   
   queue.append(node)
   
for x in graph:
   if x not in visited:
      dfsTraversal(x)

print(queue)
