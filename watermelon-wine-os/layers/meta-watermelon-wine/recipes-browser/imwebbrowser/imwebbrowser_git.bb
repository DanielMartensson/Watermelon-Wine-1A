include imwebbrowser.inc

# Runtime: WebKit needs CA certificates for HTTPS and fonts to render text.
RRECOMMENDS:${PN} = " \
	ca-certificates \
	fontconfig \
	liberation-fonts \
"
