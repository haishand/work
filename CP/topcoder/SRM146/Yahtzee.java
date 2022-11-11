
public class YahtzeeScore {
    public int maxPoints(int[] toss) {
        int count[] = new int [10];
        for(int i=0; i<toss.length; i++) {
            count[toss[i]]++;
        }
        int ret = 0;
        for(int i=1; i<=6; i++) {
            ret = Math.max(ret, i*count[i]);
        }
        return ret; 
    }

    public static void main(String[] args) {
        int[] a = {5, 3, 5, 3, 3  };
        int ret = new Yahtzee().maxPoints(a);
        System.out.println(ret);
    }
};