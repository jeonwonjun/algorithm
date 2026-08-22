class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<Map<Character, Integer>> hashList = new ArrayList<>();
        List<List<String>> answer = new ArrayList<>();

        for (String s : strs) {
            HashMap<Character, Integer> word = new HashMap<>();
            for(int i = 0; i < s.length(); i++) {
                Character c = s.charAt(i);
                word.put(c, word.getOrDefault(c, 0) + 1);
            }
            boolean flag = false;
            for (int i = 0; i < hashList.size(); i++) {
                if (hashList.get(i).equals(word)) {
                    answer.get(i).add(s);
                    flag = true;
                }
            }
            if (!flag) {
                hashList.add(word);
                answer.add(new ArrayList<>(Arrays.asList(s)));
            }
        }

        return answer;
    }
}