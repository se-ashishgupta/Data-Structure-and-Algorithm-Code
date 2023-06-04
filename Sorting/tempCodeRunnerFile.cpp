int left[n1], right[n2];
    for (int p = 0; p < n1; p++)
        left[p] = a[l + p];

    for (int p = 0; p < n2; p++)
        right[p] = a[n1 + p];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
            k