package org.alcoholic.leaf;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        MainJni JobC = new MainJni();
        int[] srcData = new int[81];
        srcData[1]  = 5;
        srcData[3]  = 6;
        srcData[15] = 7;
        srcData[16] = 3;
        srcData[21] = 1;
        srcData[31] = 7;
        srcData[33] = 8;
        srcData[37] = 6;
        srcData[43] = 5;
        srcData[45] = 1;
        srcData[54] = 7;
        srcData[58] = 4;
        srcData[60] = 2;
        srcData[65] = 4;
        srcData[67] = 3;
        srcData[75] = 5;
        srcData[79] = 6;

		int[] desData = JobC.Analysis(srcData);
		for(int i=0;i<81;i++)
		{
			Log.i("leaf",""+desData[i]);
		}

        setContentView(R.layout.main);
    }
}