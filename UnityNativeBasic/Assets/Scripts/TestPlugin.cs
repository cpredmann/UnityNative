using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class TestPlugin : MonoBehaviour
{
    private IntPtr _nativePtr;

    void Start()
    {
        _nativePtr = UnityNativeWrapper.CreateUnityNative(); 
    }

    void Update()
    {
        Debug.Log(UnityNativeWrapper.GetPointCount(_nativePtr)); 

        if (Input.anyKeyDown)
        {
            int pointCount = 100;
            UnityNativeWrapper.FillPoints(_nativePtr, pointCount);
        }
    }

    private void OnDestroy()
    {
        UnityNativeWrapper.DestroyUnityNative(_nativePtr);
    }
}
