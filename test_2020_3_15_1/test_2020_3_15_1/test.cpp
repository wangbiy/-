#if 0
//����һ������ɾ��������k�����
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
//������������У�ɾ�����������ظ��Ľ�㣬������һ���ظ���
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
//����һ���ظ�Ԫ��
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
//�����������ɾ���ظ��Ľ�㣬����һ���ظ���
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
//�������������ҹ������
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
//����һ��������������ʼ�뻷�ĵ�һ����㣬��������޻������ؿ�
Node* hasycle(Node* head)
{
	//��ȷ���л�
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
//��������ĸ�ֵ
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
	//����random����
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
	//��������������
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
