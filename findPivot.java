public static int pivot(int[] a)
{
    if (null == a) return -1;
    if (a[0] < a[a.length-1]) return -1;
    return pivot(a, 0, a.length-1);
}

private static int pivot(int[] a, int start, int stop)
{
    if (stop == start+1) return stop;
    int mid = (start + stop) / 2;
    if (a[start] < a[mid])
    {
        return pivot(a,mid,stop);
    }
    else
    {
        return pivot(a,start,mid);
    }
}
