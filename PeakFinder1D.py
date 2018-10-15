def peakFinder(array):
    n = len(array)//2
    if len(array) == 2:
        if array[0] > array[1]:
            return array[0]
        else: 
            return array[1]
    if array[n-1] > array[n]:
        return peakFinder(array[:n])
    elif array[n+1] > array[n]:
        return peakFinder(array[n+1:])
    else: 
        return array[n]
