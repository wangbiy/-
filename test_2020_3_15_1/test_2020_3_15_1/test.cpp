#if 0
//输入一个链表，删除倒数第k个结点
Node* FindkToTail(Node* head, int k)
{
	Node* front = head;
	Node* back = head;
	for (int i = 0; i < k;++i)
	{
		if (front == nullptr)
			return nullptr;
		front = front->next;
	}
	while (front != nullptr)
	{
		front = front->next;
		back = back->front;
	}
	return back;
}
//在排序的链表中，删除该链表中重复的结点，不保存一个重复的
Node* remove(Node* head)
{
	Node* fackNode = new Node;
	fackNode->next = head;
	Node* pre = fackNode;
	Node* p1 = head;
	Node* p2 = head->next;
	while (p2 != nullptr)
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != nullptr && p1->val == p2->val)
			{
				p2 = p2->next;
			}
			pre->next = p2;
			p1 = p2;
			if(p2 != nullptr)
				p2 = p2->next;
		}
	}
	return fackNode->next;
}
//保留一个重复元素
Node* remove(Node* head)
{
	Node* p1 = head;
	Node* p2 = head->next;
	while (p2 != nullptr )
	{
		if (p1->val != p2->val)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != nullptr && p1->val == p2->val)
			{
				p2 = p2->next;
			}
			p1->next = p2;
			p1 = p2;
			if (p2 != nullptr)
				p2 = p2->next;
		}
	}
	return head;
}
//非排序的链表删除重复的结点，保留一个重复的
Node* remove(Node* head)
{
	if (head == nullptr)
		return nullptr;
	unordered_map<int, int> hashTable;
	hashTable[head->val] = 1;
	Node* pre = head;
	Node* p = head->next;
	while (p != nullptr)
	{
		if (hashTable.count(p->val))
			pre->next = p->next;
		else
		{
			hashTable[p->val] = 1;
			pre = p;
		}
		p = p->next;
	}
	return head;
}
//在两个链表中找公共结点
int GetLength(Node* head)
{
	int len = 0;
	Node* cur = head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
Node* common(Node* p1, Node* p2)
{
	Node* longer = p1;
	Node* shorter = p2;
	int len1 = GetLength(p1);
	int len2 = Getlength(p2);
	int diff = len1 - len2;
	if (len2 > len1)
	{
		longer = p2;
		shorter = p1;
		diff = len2 - len1;
	}
	for (int i = 0; i < diff; ++i)
	{
		longer = longer->next;
	}
	while (shorter && longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}
//给定一个链表，返回链表开始入环的第一个结点，如果链表无环，返回空
Node* hasycle(Node* head)
{
	//先确保有环
	Node* fast = head;
	Node* slow = head;
	if (head == nullptr)
		return nullptr;
	do{
		fast = fast->next;
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
		if (fast == nullptr)
			retur nullptr;
		slow = slow->next;
	} while (fast != back);
	Node* p1 = head;
	Node* p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
//复杂链表的赋值
Node* copy(Node* head)
{
	Node* cur = head;
	while (cur != nullptr)
	{
		Node* node = new Node(cur->val);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	//进行random操作
	cur = head;
	while (cur != nullptr && cur->next != nullptr)
	{
		if (cur->random == nullptr)
		{
			cur->next->random = nullptr;
		}
		else
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//进行新链表拆出来
	cur = head;
	Node* pNewNode = head->next;
	while (cur != nullptr && cur->next != nullptr)
	{
		Node* node = cur->next;
		cur->next = node->next;
		if (node->next != nullptr)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return pNewNode;
}
#endif
