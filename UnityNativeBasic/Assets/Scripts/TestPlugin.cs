using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Runtime.InteropServices;

public class TestPlugin : MonoBehaviour
{
    private IntPtr _nativePtr;
    private GCHandle _pointHandle;
    private Vector3[] _pointData;

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
            if (!_pointHandle.IsAllocated)
            {
                _pointData = new Vector3[pointCount];
                _pointHandle = GCHandle.Alloc(_pointData, GCHandleType.Pinned);
                UnityNativeWrapper.GetPoints(_nativePtr, _pointHandle.AddrOfPinnedObject());
            }
            Debug.LogWarning(_pointData[50].ToString());
        }
    }

    private void OnDestroy()
    {
        UnityNativeWrapper.DestroyUnityNative(_nativePtr);
        _pointHandle.Free();
    }
}
