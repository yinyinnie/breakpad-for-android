package cn.onlinecache.breakpad.demo;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.widget.Button;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;
import cn.onlinecache.breakpad.NativeBreakpad;

public class MainActivity extends AppCompatActivity {

    @BindView(R.id.btnTestNDKCrash)
    Button btnTestNDKCrash;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ButterKnife.bind(this);

        NativeBreakpad.init(Environment.getExternalStorageDirectory().getAbsolutePath());
    }

    @OnClick(R.id.btnTestNDKCrash)
    void testNDKCrash(){
        NativeBreakpad.testNativeCrash();
    }
}
