#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/discuss/40540/88ms!-Accepted-c++-solution-with-two-end-BFS.-68ms-for-Word-Ladder-and-88ms-for-Word-Ladder-II
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end()); //תΪset
		unordered_set<string> startWords, endWords; //��β����BFS�Ľ��
		startWords.insert(beginWord);
		if (dict.count(endWord)) endWords.insert(endWord);
		unordered_map<string, vector<string>> children; //�洢���������·��
		bool flip = false; //������BFS��־
		vector<vector<string>> ladders;
		vector<string> ladder;
		ladder.push_back(beginWord);
		if (search(startWords, endWords, dict, children, flip))
			getLadders(beginWord, endWord, children, ladder, ladders);
		return ladders;
	}
private:
	bool search(unordered_set<string>& startWords, unordered_set<string>& endWords, 
		unordered_set<string>& dict, unordered_map<string, vector<string>>& children, bool flip)
	{
		if (startWords.empty()) return false;
		if (startWords.size() > endWords.size()) //��תΪBFS������С�ļ���
			return search(endWords, startWords, dict, children, !flip);
		//ɾ���Ѿ����ʵĽ��
		for (string e : startWords) dict.erase(e);
		for (string e : endWords) dict.erase(e);
		//BFS startWords
		unordered_set<string> nextlayer;
		bool done = false;
		for (string word : startWords)
		{
			int len = word.length();
			for (int i = 0; i < len; i++)
			{
				string temp(word);
				for (int j = 0; j < 26; j++)
				{
					temp[i] = j + 'a';
					if (endWords.count(temp))
					{
						done = true;
						flip ? children[temp].push_back(word) : children[word].push_back(temp);
					}
					else if (!done && dict.count(temp))
					{
						nextlayer.insert(temp);
						flip ? children[temp].push_back(word) : children[word].push_back(temp);
					}
				}
			}
		}
		return done || (search(nextlayer, endWords, dict, children, flip));
	}
	
	void getLadders(string& start, string& end, unordered_map<string, vector<string> >& children,
		vector<string>& ladder, vector<vector<string> >& ladders)
	{
		if (start == end)
		{
			ladders.push_back(ladder);
			return;
		}
		for (string child : children[start])
		{
			ladder.push_back(child);
			getLadders(child, end, children, ladder, ladders);
			ladder.pop_back(); //����
		}
	}
};

