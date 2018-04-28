package org.alcoholic.leaf;

import android.os.Bundle;

public class MainJni
{
    static
    {
        System.loadLibrary("leaf");
    }

    public native int[] Analysis(int[] data);
}
