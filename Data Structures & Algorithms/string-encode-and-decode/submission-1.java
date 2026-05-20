

class Solution {

    // Encode list of strings to a single string
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s.length()).append('#').append(s);
        }
        return sb.toString();
    }

    // Decode single string back to list of strings
    public List<String> decode(String str) {
        List<String> result = new ArrayList<>();
        int i = 0;
        while (i < str.length()) {
            int j = i;
            // Find the separator #
            while (str.charAt(j) != '#') j++;
            int length = Integer.parseInt(str.substring(i, j));
            String s = str.substring(j + 1, j + 1 + length);
            result.add(s);
            i = j + 1 + length; // Move to next string
        }
        return result;
    }
}
