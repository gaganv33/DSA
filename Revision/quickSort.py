def quicksort(alist, start, end):
   if end - start > 1:
      mid = (start + end) // 2
      p = partition(alist, start, end)
      quicksort(alist, start, p)
      quicksort(alist, p + 1, end)

def partition(alist, start, end):
   pivot = alist[start]
   i = start + 1;
   j = end - 1

   while(True):
      while(i <= j and alist[i] <= pivot):
         i = i + 1
      while(i <= j and alist[j] >= pivot):
         j = j - 1
      
      if(i <= j):
         alist[i], alist[j] = alist[j], alist[i]
      else:
         alist[start], alist[j] = alist[j], alist[start]
         return j

alist = input("enter the list of numbers: ").split()
alist = [int(x) for x in alist]
quicksort(alist, 0, len(alist))
print(alist)
