void quick_sort(int arr[],int l,int r)
{
	if(l<r)
	{
		int i= l,j=r, X=arr[i];
		while(i<j)
		{
			//从右向左找比X小的数
			while(i<j&&X<arr[j])
				j--;
			if(i<j)
				arr[i++]=arr[j];
			//从左往右找比X大的数
			while(i<j&&X>arr[i])
				i++;
			if(i<j)
				arr[j--]=arr[i];
		}
		arr[i]=X;
		quick_sort(arr,l,i-1);
		quick_sort(arr,i+1,r);
	}
}
