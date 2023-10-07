def unique_sublists(lst):
    sublists = []
    n = len(lst)
    
    for i in range(n):
        for j in range(i+1, n+1):
            sublist = lst[i:j]
            if sublist not in sublists:
                sublists.append(sublist)
                
    return sublists

result = unique_sublists([1, 2, 3])
print(result)
