bool checkIfPangram(string sentence) {
        unordered_map<char,int> ump;
        
        for(int i=0;i<sentence.size();i++)
        {
            ump[sentence[i]]++;
            
            if(ump.size()==26) return true;
        }
        return false;
    }
