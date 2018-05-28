#import <WebKit/WebKit.h>
#import "CDVRemoteInjection.h"
#import "CDVRemoteInjectionWebViewBaseDelegate.h"

@interface CDVRemoteInjectionWKWebViewDelegate: CDVRemoteInjectionWebViewBaseDelegate <CDVRemoteInjectionWebViewDelegate>
@property (readwrite, weak) CDVRemoteInjectionPlugin *plugin;
@property (readwrite, retain) NSCondition *waitHandle;
@property (readwrite, retain) NSString *scriptBundle;
- (void) onWebViewDidFinishLoad:(WKWebView *)webView;
- (void) onWebViewDidStartProvisionalNavigation;
- (void) onWebViewDidFailNavigation:(NSError *)error;
@end

@interface CDVRemoteInjectionWKWebViewNavigationDelegate: WrappedDelegateProxy <WKNavigationDelegate>
@property (readwrite, weak) CDVRemoteInjectionWKWebViewDelegate *webViewDelegate;
@end
