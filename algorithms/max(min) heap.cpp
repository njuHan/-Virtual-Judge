
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) //iΪ�����, siftdown
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
//max heap
//����
void siftdown(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int j = 2 * i + 1;  // left = 2*i + 1
	int temp = arr[i]; //������Ԫ��һֱ���� temp
	while (j<n)
	{
		if (j+1<n && arr[j+1] > arr[j]) j++; //ָ��ϴ���ӽ��
		if (temp <arr[j] ) {arr[i] =  arr[j]; i = j; j = 2*i + 1;}
		else break;
	}
	arr[i] = temp; //���������� ����temp
}

// max heap siftup
void siftup(int arr[], int son) 
{
	int j = son;
	int i = (j-1)/2; //i Ϊ�����
	int temp = arr[j];
	while (i>=0)
	{
		if (arr[i] < temp)
		{
			arr[j] = arr[i];  //��СԪ������
			j = i;
			i = (j-1)/2; //�����±����ƣ� siftup
		}
		else break;
	}
	arr[j] = temp; //����
}
//�ݹ�
void siftup2(int arr[], int son) 
{
	int j = son;
	int i = (j-1)/2; //i Ϊ�����
	if (i >=0 && arr[i]<arr[j])
	{
		swap(arr[i], arr[j]);
		siftup2(arr, i);
	}
}

//���ѣ���β����Ԫ��
//�����ǿռ䲻������
void insert(int arr[], int size, int x)
{
	arr[size] = x;
	siftup(arr, size); 
	size++;
}

//����ɾ����ɾ���Ѷ�Ԫ��


// main function to do heap sort
void heapSort(int arr[], int n)
{
	//case1: right = 2*i + 2(ż��) = n - 1 , -> i = (n-2)/2, n Ϊ������ȡ���� 
	//case2: left = 2*i + 1(����) = n-1, i = (n-2)/2, nΪż��, ����case1,2������ i = (n-2)/2
	
	// Build max heap (rearrange array) by using siftdown method
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		//����������Χ��ĩβ�ź����Ԫ�ز����� 
		heapify(arr, i, 0);
	}
}