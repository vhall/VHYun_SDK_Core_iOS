// VHURLResponseSerialization.h
// Copyright (c) 2011–2016 Alamofire Software Foundation ( http://alamofire.org/ )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `VHURLResponseSerialization` protocol is adopted by an object that decodes data into a more useful object representation, according to details in the server response. Response serializers may additionally perform validation on the incoming response and data.

 For example, a JSON response serializer may check for an acceptable status code (`2XX` range) and content type (`application/json`), decoding a valid JSON response into an object.
 */
@protocol VHURLResponseSerialization <NSObject, NSSecureCoding, NSCopying>

/**
 The response object decoded from the data associated with a specified response.

 @param response The response to be processed.
 @param data The response data to be decoded.
 @param error The error that occurred while attempting to decode the response data.

 @return The object decoded from the specified response data.
 */
- (nullable id)responseObjectForResponse:(nullable NSURLResponse *)response
                           data:(nullable NSData *)data
                          error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NOTHROW;

@end

#pragma mark -

/**
 `VHHTTPResponseSerializer` conforms to the `VHURLRequestSerialization` & `VHURLResponseSerialization` protocols, offering a concrete base implementation of query string / URL form-encoded parameter serialization and default request headers, as well as response status code and content type validation.

 Any request or response serializer dealing with HTTP is encouraged to subclass `VHHTTPResponseSerializer` in order to ensure consistent default behavior.
 */
@interface VHHTTPResponseSerializer : NSObject <VHURLResponseSerialization>

- (instancetype)init;

@property (nonatomic, assign) NSStringEncoding stringEncoding DEPRECATED_MSG_ATTRIBUTE("The string encoding is never used. VHHTTPResponseSerializer only validates status codes and content types but does not try to decode the received data in any way.");

/**
 Creates and returns a serializer with default configuration.
 */
+ (instancetype)serializer;

///-----------------------------------------
/// @name Configuring Response Serialization
///-----------------------------------------

/**
 The acceptable HTTP status codes for responses. When non-`nil`, responses with status codes not contained by the set will result in an error during validation.

 See http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
 */
@property (nonatomic, copy, nullable) NSIndexSet *acceptableStatusCodes;

/**
 The acceptable MIME types for responses. When non-`nil`, responses with a `Content-Type` with MIME types that do not intersect with the set will result in an error during validation.
 */
@property (nonatomic, copy, nullable) NSSet <NSString *> *acceptableContentTypes;

/**
 Validates the specified response and data.

 In its base implementation, this method checks for an acceptable status code and content type. Subclasses may wish to add other domain-specific checks.

 @param response The response to be validated.
 @param data The data associated with the response.
 @param error The error that occurred while attempting to validate the response.

 @return `YES` if the response is valid, otherwise `NO`.
 */
- (BOOL)validateResponse:(nullable NSHTTPURLResponse *)response
                    data:(nullable NSData *)data
                   error:(NSError * _Nullable __autoreleasing *)error;

@end

#pragma mark -


/**
 `VHJSONResponseSerializer` is a subclass of `VHHTTPResponseSerializer` that validates and decodes JSON responses.

 By default, `VHJSONResponseSerializer` accepts the following MIME types, which includes the official standard, `application/json`, as well as other commonly-used types:

 - `application/json`
 - `text/json`
 - `text/javascript`

 In RFC 7159 - Section 8.1, it states that JSON text is required to be encoded in UTF-8, UTF-16, or UTF-32, and the default encoding is UTF-8. NSJSONSerialization provides support for all the encodings listed in the specification, and recommends UTF-8 for efficiency. Using an unsupported encoding will result in serialization error. See the `NSJSONSerialization` documentation for more details.
 */
@interface VHJSONResponseSerializer : VHHTTPResponseSerializer

- (instancetype)init;

/**
 Options for reading the response JSON data and creating the Foundation objects. For possible values, see the `NSJSONSerialization` documentation section "NSJSONReadingOptions". `0` by default.
 */
@property (nonatomic, assign) NSJSONReadingOptions readingOptions;

/**
 Whether to remove keys with `NSNull` values from response JSON. Defaults to `NO`.
 */
@property (nonatomic, assign) BOOL removesKeysWithNullValues;

/**
 Creates and returns a JSON serializer with specified reading and writing options.

 @param readingOptions The specified JSON reading options.
 */
+ (instancetype)serializerWithReadingOptions:(NSJSONReadingOptions)readingOptions;

@end

#pragma mark -

/**
 `VHXMLParserResponseSerializer` is a subclass of `VHHTTPResponseSerializer` that validates and decodes XML responses as an `NSXMLParser` objects.

 By default, `VHXMLParserResponseSerializer` accepts the following MIME types, which includes the official standard, `application/xml`, as well as other commonly-used types:

 - `application/xml`
 - `text/xml`
 */
@interface VHXMLParserResponseSerializer : VHHTTPResponseSerializer

@end

#pragma mark -

#ifdef __MAC_OS_X_VERSION_MIN_REQUIRED

/**
 `VHXMLDocumentResponseSerializer` is a subclass of `VHHTTPResponseSerializer` that validates and decodes XML responses as an `NSXMLDocument` objects.

 By default, `VHXMLDocumentResponseSerializer` accepts the following MIME types, which includes the official standard, `application/xml`, as well as other commonly-used types:

 - `application/xml`
 - `text/xml`
 */
@interface VHXMLDocumentResponseSerializer : VHHTTPResponseSerializer

- (instancetype)init;

/**
 Input and output options specifically intended for `NSXMLDocument` objects. For possible values, see the `NSXMLDocument` documentation section "Input and Output Options". `0` by default.
 */
@property (nonatomic, assign) NSUInteger options;

/**
 Creates and returns an XML document serializer with the specified options.

 @param mask The XML document options.
 */
+ (instancetype)serializerWithXMLDocumentOptions:(NSUInteger)mask;

@end

#endif

#pragma mark -

/**
 `VHPropertyListResponseSerializer` is a subclass of `VHHTTPResponseSerializer` that validates and decodes XML responses as an `NSXMLDocument` objects.

 By default, `VHPropertyListResponseSerializer` accepts the following MIME types:

 - `application/x-plist`
 */
@interface VHPropertyListResponseSerializer : VHHTTPResponseSerializer

- (instancetype)init;

/**
 The property list format. Possible values are described in "NSPropertyListFormat".
 */
@property (nonatomic, assign) NSPropertyListFormat format;

/**
 The property list reading options. Possible values are described in "NSPropertyListMutabilityOptions."
 */
@property (nonatomic, assign) NSPropertyListReadOptions readOptions;

/**
 Creates and returns a property list serializer with a specified format, read options, and write options.

 @param format The property list format.
 @param readOptions The property list reading options.
 */
+ (instancetype)serializerWithFormat:(NSPropertyListFormat)format
                         readOptions:(NSPropertyListReadOptions)readOptions;

@end

#pragma mark -

/**
 `VHImageResponseSerializer` is a subclass of `VHHTTPResponseSerializer` that validates and decodes image responses.

 By default, `VHImageResponseSerializer` accepts the following MIME types, which correspond to the image formats supported by UIImage or NSImage:

 - `image/tiff`
 - `image/jpeg`
 - `image/gif`
 - `image/png`
 - `image/ico`
 - `image/x-icon`
 - `image/bmp`
 - `image/x-bmp`
 - `image/x-xbitmap`
 - `image/x-win-bitmap`
 */
@interface VHImageResponseSerializer : VHHTTPResponseSerializer

#if TARGET_OS_IOS || TARGET_OS_TV || TARGET_OS_WATCH
/**
 The scale factor used when interpreting the image data to construct `responseImage`. Specifying a scale factor of 1.0 results in an image whose size matches the pixel-based dimensions of the image. Applying a different scale factor changes the size of the image as reported by the size property. This is set to the value of scale of the main screen by default, which automatically scales images for retina displays, for instance.
 */
@property (nonatomic, assign) CGFloat imageScale;

/**
 Whether to automatically inflate response image data for compressed formats (such as PNG or JPEG). Enabling this can significantly improve drawing performance on iOS when used with `setCompletionBlockWithSuccess:failure:`, as it allows a bitmap representation to be constructed in the background rather than on the main thread. `YES` by default.
 */
@property (nonatomic, assign) BOOL automaticallyInflatesResponseImage;
#endif

@end

#pragma mark -

/**
 `VHCompoundSerializer` is a subclass of `VHHTTPResponseSerializer` that delegates the response serialization to the first `VHHTTPResponseSerializer` object that returns an object for `responseObjectForResponse:data:error:`, falling back on the default behavior of `VHHTTPResponseSerializer`. This is useful for supporting multiple potential types and structures of server responses with a single serializer.
 */
@interface VHCompoundResponseSerializer : VHHTTPResponseSerializer

/**
 The component response serializers.
 */
@property (readonly, nonatomic, copy) NSArray <id<VHURLResponseSerialization>> *responseSerializers;

/**
 Creates and returns a compound serializer comprised of the specified response serializers.

 @warning Each response serializer specified must be a subclass of `VHHTTPResponseSerializer`, and response to `-validateResponse:data:error:`.
 */
+ (instancetype)compoundSerializerWithResponseSerializers:(NSArray <id<VHURLResponseSerialization>> *)responseSerializers;

@end

///----------------
/// @name Constants
///----------------

/**
 ## Error Domains

 The following error domain is predefined.

 - `NSString * const VHURLResponseSerializationErrorDomain`

 ### Constants

 `VHURLResponseSerializationErrorDomain`
 VHURLResponseSerializer errors. Error codes for `VHURLResponseSerializationErrorDomain` correspond to codes in `NSURLErrorDomain`.
 */
FOUNDATION_EXPORT NSString * const VHURLResponseSerializationErrorDomain;

/**
 ## User info dictionary keys

 These keys may exist in the user info dictionary, in addition to those defined for NSError.

 - `NSString * const VHNetworkingOperationFailingURLResponseErrorKey`
 - `NSString * const VHNetworkingOperationFailingURLResponseDataErrorKey`

 ### Constants

 `VHNetworkingOperationFailingURLResponseErrorKey`
 The corresponding value is an `NSURLResponse` containing the response of the operation associated with an error. This key is only present in the `VHURLResponseSerializationErrorDomain`.

 `VHNetworkingOperationFailingURLResponseDataErrorKey`
 The corresponding value is an `NSData` containing the original data of the operation associated with an error. This key is only present in the `VHURLResponseSerializationErrorDomain`.
 */
FOUNDATION_EXPORT NSString * const VHNetworkingOperationFailingURLResponseErrorKey;

FOUNDATION_EXPORT NSString * const VHNetworkingOperationFailingURLResponseDataErrorKey;

NS_ASSUME_NONNULL_END
