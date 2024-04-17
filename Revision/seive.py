n = int(input("Enter the value of n: "))
visit = [True for i in range(n + 1)]

p = 2

while(p * p <= n):
   if(visit[p]):
      for j in range(p * p, n + 1, p):
         visit[j] = False

   p += 1

for i in range(2, n + 1):
   if(visit[i]):
      print(str(i) + " ")
