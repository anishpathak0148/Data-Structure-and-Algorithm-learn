#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
// representation of Min Heap Node.
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left,*right;

    MinHeapNode(char data, unsigned freq)
    {
        this->data=data;
        this->freq=freq;
        left=NULL;
        right=NULL;
    }
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }
};

unordered_map<char,string> generateCode(MinHeapNode* root, string str, unordered_map<char,string>hm)
{
    if(root==NULL)
        return hm;
    if(root->data !='$')
    {
        hm.insert(make_pair(root->data, str));
    }
    hm = generateCode(root->left, str+"0", hm);
    hm = generateCode(root->right, str+"1", hm);
    return hm;
}
pair<string, MinHeapNode*> Compress(string s)
{
    unordered_map<char,unsigned> hm;
    for(int i=0;i<s.length();i++)
    {
        hm[s[i]]++;
    }
    cout<<"Size of HashMap is:"<<hm.size()<<endl;
    cout<<"Hash table is"<<endl;
    for(auto ele : hm)
    {
        cout<<ele.first<<"\t"<<ele.second<<endl;
    }

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for(auto ele : hm)
    {
        minHeap.push(new MinHeapNode(ele.first, ele.second));
    }
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        MinHeapNode* left = minHeap.top();
        minHeap.pop();

        MinHeapNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    // call the generateCode function.
    unordered_map<char,string> codeMap;
    codeMap = generateCode(minHeap.top(), "", codeMap);
    //print the code...
    cout<<endl;
    cout<<endl;

    cout<<"Character\tCode"<<endl;
    for(auto ele : codeMap)
    {
        cout<<ele.first<<"\t\t"<<ele.second<<endl;
    }

    string encodedMsg="";
    for(int i=0;i<s.length();i++)
    {
        encodedMsg += codeMap[s[i]];
    }

    cout<<endl;
    int bits=0;
    bits += 8*codeMap.size() + encodedMsg.length();
    cout<<"Total no of bits after compressing the message is: "<<bits<<endl;

    return make_pair(encodedMsg, minHeap.top());
}

string decode_file(struct MinHeapNode* root, string s)
{
MinHeapNode *temp = root;
string str="";
for(int i=0;i<s.length();i++)
{
    if(s[i]=='0')
    {
        temp=temp->left;
    }
    if(s[i]=='1')
    {
        temp = temp->right;
    }
    if(temp->left==nullptr && temp->right==nullptr)
    {
        str = str+temp->data;
        temp=root;
    }
}
return str;
}
main()
{
    string s;
    cout<<"Enter a message so that it can be encoded:";
    cin>>s;
    int Nbit = s.length()*8;
    cout<<"No of bits before Compress the message is: "<<Nbit<<endl;
    auto it = Compress(s);
    string EncodeMsg = it.first;
    MinHeapNode *root = it.second;
    cout<<endl;
    cout<<"Encoded Message is: "<<EncodeMsg<<endl;
    cout<<endl;
    string DecodeMsg = decode_file(root, EncodeMsg);
    cout<<"Decoded Message is: "<<DecodeMsg;
}
