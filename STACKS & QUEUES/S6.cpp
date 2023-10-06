#include<bits/stdc++.h>
using namespace std;
// LRU Cache
// TC: O(N)
// SC: O(1)
class LRUCache {
public:
    class Node {
      public:
        int key;
      int val;
      Node * next;
      Node * prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);
    int cap;
    unordered_map < int, Node * > mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertNode(Node * newNode){
       Node* temp= head->next;
       newNode->next=temp;
       newNode -> prev = head;
       head -> next = newNode;
       temp -> prev = newNode;
    }
    void deleteNode(Node * node){
        Node* temp1=node->next;
        Node* temp2=node->prev;
        temp2->next=temp1;
        temp1->prev=temp2;
    }
    int get(int _key) {
           if (mp.find(_key) != mp.end()) {
                Node * node = mp[_key];
                int ans = node -> val;
                mp.erase(_key);
                deleteNode(node);
                insertNode(node);
                mp[_key] = head -> next;
           return ans;
          }
        return -1;
}
    
    void put(int _key, int value) {
         if(mp.find(_key)!=mp.end()){
             Node* existing_Node = mp[_key];
             mp.erase(_key);
             deleteNode(existing_Node);
         }
         if(mp.size()==cap){
             mp.erase(tail->prev->key);
             deleteNode(tail->prev);
         }
         insertNode(new Node(_key,value));
         mp[_key]=head->next;
    }
};
// LFU CACHE
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    
    
    
};
class LFUCache
{
     map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:

    LFUCache(int capacity)
    {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    int get(int key)
    {
         if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }

    void put(int key, int value)
    {
         if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};
