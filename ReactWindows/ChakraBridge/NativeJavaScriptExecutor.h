#pragma once

#include "pch.h"
#include "ChakraHost.h"
#include "ChakraStringResult.h"

using namespace Platform;

namespace ChakraBridge {

/// <summary>
/// This class interfaces with the unmanaged JSRT Chakra Host.
/// </summary>
public ref class NativeJavaScriptExecutor sealed
{
public:
	/// <summary>
	/// Initializes the JSRT session.
	/// </summary>
	/// <returns>
	/// JsNoError is no error, else a JsErrorCode with the appropriate error.
	/// </returns>
    int InitializeHost();

	/// <summary>
	/// Disposes the current JSRT session.
	/// </summary>
	/// <returns>
	/// JsNoError is no error, else a JsErrorCode with the appropriate error.
	/// </returns>
    int DisposeHost();

	/// <summary>
	/// Gets the global variable value.
	/// </summary>
	/// <param name="variableName">The global variable to get.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
    ChakraStringResult GetGlobalVariable(String^ variableName);

	/// <summary>
	/// Sets the global variable
	/// </summary>
	/// <param name="variableName">The variable name to set.</param>
	/// <param name="value">The value to set on the global variable.</param>
	/// <returns>
	/// JsNoError is no error, else a JsErrorCode with the appropriate error.
	/// </returns>
    int SetGlobalVariable(String^ variableName, String^ value);

	/// <summary>
	/// Runs the given script with the source URI and returns the result.
	/// </summary>
	/// <param name="source">The source of the script to run.</param>
	/// <param name="sourceUri">The source URI of the script to run.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
    ChakraStringResult RunScript(String^ source, String^ sourceUri);

	/// <summary>
	/// Runs the script from the file location and source URI and returns the result.
	/// </summary>
	/// <param name="sourceFilePath">The file path which contains the source to run.</param>
	/// <param name="sourceUri">The source URI of the script to run.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
    ChakraStringResult RunScriptFromFile(String^ sourceFilePath, String^ sourceUri);

	/// <summary>
	/// Serializes a source script to a file destination.
	/// </summary>
	/// <param name="source">The source script to serialize.</param>
	/// <param name="destination">The destination to save the serialized script.</param>
	/// <returns>
	/// JsNoError is no error, else a JsErrorCode with the appropriate error.
	/// </returns>
	int SerializeScript(String^ source, String^ destination);

	/// <summary>
	/// Serializes a script from a file location with source URI.
	/// </summary>
	/// <param name="file">The location of the source file to serialize.</param>
	/// <param name="destination">The destination to save the serialized source.</param>
	/// <returns>
	/// JsNoError is no error, else a JsErrorCode with the appropriate error.
	/// </returns>
	int SerializeScriptFromFile(String^ file, String^ destination);

	/// <summary>
	/// Runs a serialized script from the byte array, source file path, and source URI.
	/// </summary>
	/// <param name="buffer">The buffer containing the serialized script.</param>
	/// <param name="sourceFilePath">The path of the source file.</param>
	/// <param name="sourceUri">The source URI.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
	ChakraStringResult RunSerializedScript(const Array<byte>^ buffer, String^ sourceFilePath, String^ sourceUri);
	
	/// <summary>
	/// Runs a serialzed script from the serialized path, the source file path and source URI.
	/// </summary>
	/// <param name="serializedPath">The path containing the serailized script.</param>
	/// <param name="sourceFilePath">The path of the source file.</param>
	/// <param name="sourceUri">The source URI.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
	ChakraStringResult RunSerializedScriptFromFile(String^ serializedPath, String^ sourceFilePath, String^ sourceUri);

	/// <summary>
	/// Calls the underlying function with the given module and method name and JSON stringified arguments.
	/// </summary>
	/// <param name="moduleName">The module name to call.</param>
	/// <param name="methodName">The method name on the module to call.</param>
	/// <param name="args">JSON stringified arguments to call on the module.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
    ChakraStringResult CallFunctionAndReturnFlushedQueue(String^ moduleName, String^ methodName, String^ args); 
    
	/// <summary>
	/// Calls the underlying function with the callback ID and JSON stringified arguments.
	/// </summary>
	/// <param name="callbackId">The callback ID.</param>
	/// <param name="args">JSON stringified arguments to call on the module.</param>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
	ChakraStringResult InvokeCallbackAndReturnFlushedQueue(int callbackId, String^ args); 
    
	/// <summary>
	/// Calls the flush queue function.
	/// </summary>
	/// <returns>
	/// A compount result with the JSON stringified value and an error code if any occurred.
	/// </returns>
	ChakraStringResult FlushedQueue(); 
private:
    ChakraHost host;
};

};
