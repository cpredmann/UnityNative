using System.Runtime.InteropServices;
using UnityEngine;
using System;


public class UnityNativeWrapper
{

    [DllImport("UnityNativeWrapper", CallingConvention =CallingConvention.Cdecl)]
    public static extern IntPtr CreateUnityNative();

    [DllImport("UnityNativeWrapper", CallingConvention =CallingConvention.Cdecl)]
    public static extern int GetPointCount(IntPtr unityNative);

    [DllImport("UnityNativeWrapper", CallingConvention =CallingConvention.Cdecl)]
    public static extern void FillPoints(IntPtr unityNative, int count);

    [DllImport("UnityNativeWrapper", CallingConvention =CallingConvention.Cdecl)]
    public static extern void DestroyUnityNative(IntPtr unityNative);
}
