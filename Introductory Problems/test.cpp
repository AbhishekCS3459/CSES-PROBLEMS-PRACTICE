struct Node
{
    bool flag;
    Node *links[26];
    bool is_contains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *referenceNode)
    {
        links[ch - 'a'] = referenceNode;
    }
    void set_end()
    {
        flag = true;
    }
    bool is_end()
    {
        return flag;
    }
    Node *get_next(char ch)
    {
        return links[ch - 'a'];
    }
};

class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (auto in : word)
        {
            if (!node->is_contains(in))
            {
                node->put(in, new Node());
            }
            node = node->get_next(in);
        }
        node->set_end();
        return;
    }
    bool rec_help(int idx, string word, Node *node)
    {
        if (idx == word.length())
        {
            return node->is_end();
        }

        if (word[idx] == '.')
        {
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (node->is_contains(word[idx]))
                {
                    return rec_help(idx + 1, word, node->get_next(ch));
                }
            }
            return false;
        }
        else
        {
            if (node->is_contains(word[idx]) && rec_help(idx + 1, word, node->get_next(word[idx])))
            {
                return true;
            }
            return false;
        }
        return false;
    }
    bool search(string word)
    {
        return rec_help(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */