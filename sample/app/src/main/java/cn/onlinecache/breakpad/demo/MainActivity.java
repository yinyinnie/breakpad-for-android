package cn.onlinecache.breakpad.demo;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;

import cn.onlinecache.breakpad.NativeBreakpad;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        NativeBreakpad.init(Environment.getExternalStorageDirectory().getAbsolutePath());
    }
}
