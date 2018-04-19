class Main {
    public static void main(String[] args) {
        int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int result = 0;
        for (int i = 1; i <= 31; i++) {
            if (i <= days[i / 10 + i % 10])
                result++;
        }
        System.out.println(result);
    }
}