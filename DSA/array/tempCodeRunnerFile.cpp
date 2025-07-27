void Display(struct Array arr)
{
    int i;
    printf("\n Elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}