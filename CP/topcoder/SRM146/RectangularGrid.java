public class RectangularGrid {
    long countRectangles(int width, int height) {
        long cnt = 0;
        for(int i=1; i<=width; i++) {
            for(int j=1; j<=height; j++) {
                if(i==j) continue;
                cnt += (height-j+1)*(width-i+1);
                /*
                for(int ll=0; ll+i<=width; ll++) {
                    for(int rr=0; rr+j<=height; rr++) {
                        cnt++;
                    }
                }
                */
//                System.out.println("("+i+","+j+")"+":"+cnt);
            }
        }       
        return cnt;
    }
    public static void main(String[] args) {
        long ret = new RectangularGrid().countRectangles(592, 964);
        System.out.println(ret);
    }
}