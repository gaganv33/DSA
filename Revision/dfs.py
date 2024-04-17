graph = {
   '5' : ['3', '7'],
   '3' : ['2', '4'],
   '7' : ['8'],
   '2' : [],
   '4' : ['8'],
   '8' : []
}

visitied = []

def dfsTraversal(node):
   print(node)
   visitied.append(node)

   for x in graph[node]:
      if x not in visitied:
         dfsTraversal(x)

for x in graph:
   if x not in visitied:
      dfsTraversal(x)


