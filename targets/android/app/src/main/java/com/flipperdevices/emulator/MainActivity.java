package com.flipperdevices.emulator;

import android.app.Activity;
import android.os.Bundle;
import android.view.SurfaceView;
import android.view.SurfaceHolder;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class MainActivity extends Activity {
    
    static {
        System.loadLibrary("flipper_native");
    }
    
    private SurfaceView surfaceView;
    private EmulatorThread emulatorThread;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        surfaceView = new SurfaceView(this);
        setContentView(surfaceView);
        
        surfaceView.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(SurfaceHolder holder) {
                emulatorThread = new EmulatorThread(holder);
                emulatorThread.start();
            }
            
            @Override
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
                // Handle surface changes
            }
            
            @Override
            public void surfaceDestroyed(SurfaceHolder holder) {
                if (emulatorThread != null) {
                    emulatorThread.stopRunning();
                    try {
                        emulatorThread.join();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
    }
    
    private class EmulatorThread extends Thread {
        private SurfaceHolder holder;
        private boolean running = true;
        
        public EmulatorThread(SurfaceHolder holder) {
            this.holder = holder;
        }
        
        public void stopRunning() {
            running = false;
        }
        
        @Override
        public void run() {
            // Initialize Flipper firmware
            nativeInit();
            
            while (running) {
                Canvas canvas = null;
                try {
                    canvas = holder.lockCanvas();
                    if (canvas != null) {
                        // Clear canvas
                        canvas.drawColor(Color.BLACK);
                        
                        // Draw Flipper display
                        Paint paint = new Paint();
                        paint.setColor(Color.WHITE);
                        paint.setTextSize(40);
                        canvas.drawText("Flipper Zero Emulator", 50, 100, paint);
                        
                        // Update emulator state
                        nativeUpdate();
                    }
                } finally {
                    if (canvas != null) {
                        holder.unlockCanvasAndPost(canvas);
                    }
                }
                
                try {
                    Thread.sleep(16); // ~60 FPS
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            
            // Cleanup
            nativeCleanup();
        }
    }
    
    // Native methods
    private native void nativeInit();
    private native void nativeUpdate();
    private native void nativeCleanup();
}
