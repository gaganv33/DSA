graph = {
   '5' : ['3', '7'],
   '3' : ['2', '4'],
   '7' : ['8'],
   '2' : [],
   '4' : ['8'],
   '8' : []
}

visited = []
queue = []

def bfsTrversal(node):
   queue.append(node)
   visited.append(node)

   while queue:
      m = queue.pop(0)

      print(str(m) + " ")


      for x in graph[m]:
         if x not in visited:
            queue.append(x)
            visited.append(x)

for x in graph:
   if x not in visited:
      bfsTrversal(x)
      
