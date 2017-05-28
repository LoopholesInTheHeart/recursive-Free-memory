//逆序实现film结构内存释放，采用尾递归方法

//原结构体
struct  film{
	char name[TSIZE];
	int data;
struct film * next;   //指向下一个地址
};
//声明，传入参数为 链表头 head
struct film * GcMemony(film *);
//尾递归实现内存释放
struct film * GcMemony(film * head)
	{
	int n = 0;

	if (head->next != NULL)
	{
		//printf("GC start at %d\n", n = head->data);
		head->next = GcMemony(head->next);
	}
	if (head->next == NULL)
	{
		//printf("free start at %d\n", n = head->data);
		free(head);
		//printf("free %d end\n", n);
		return NULL;
	}
}