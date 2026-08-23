class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character, String> map = new HashMap<>();
        HashMap<String, Character> smap = new HashMap<>();
        
        String[] strs = s.split(" ");
        if (strs.length != pattern.length()) {
            return false;
        }

        for (int i = 0; i < pattern.length(); i++) {
            Character c = pattern.charAt(i);
            String stmp = map.getOrDefault(c, "");
            Character sc = smap.getOrDefault(strs[i], ' ');
            if (stmp.equals("") && sc.equals(' ')) {
                map.put(c, strs[i]);
                smap.put(strs[i], c);
            } else if (stmp.equals(strs[i]) && sc.equals(c)) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
}