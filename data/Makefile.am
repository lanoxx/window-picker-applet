appletdir       = $(datadir)/gnome-panel/4.0/applets
applet_in_files = org.gnome.applets.WindowPicker.panel-applet.in
applet_DATA     = $(applet_in_files:.panel-applet.in=.panel-applet)

uidir = $(datadir)/$(PACKAGE)/ui
ui_DATA = \
	menu.xml \
	window-picker-about-logo.png

$(applet_in_files): $(applet_in_files).in Makefile
	$(AM_V_GEN)sed \
	-e "s|\@LIBEXECDIR\@|$(libexecdir)|" \
	-e "s|\@VERSION\@|$(PACKAGE_VERSION)|" \
	$< > $@


gsettings_file = org.gnome.gnome-applets.window-picker-applet.gschema.xml
gsettings_SCHEMAS = $(gsettings_file)

@INTLTOOL_XML_NOMERGE_RULE@

$(gsettings_file).in: $(gsettings_file).in.in
	sed \
	  -e "s|\@GETTEXT_PACKAGE\@|$(GETTEXT_PACKAGE)|" \
	  $< > $@

@GSETTINGS_RULES@

%.panel-applet: %.panel-applet.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

servicedir       = $(datadir)/dbus-1/services
service_in_files = org.gnome.panel.applet.WindowPickerFactory.service.in
service_DATA     = $(service_in_files:.service.in=.service)

org.gnome.panel.applet.WindowPickerFactory.service: $(service_in_files)
	$(AM_V_GEN)sed \
	-e "s|\@LIBEXECDIR\@|$(libexecdir)|" \
	$< > $@

APPLET_LOCATION=$(libexecdir)/window-picker-applet

EXTRA_DIST = \
	$(WINDOW_PICKER_MENU_UI_DIR) \
	org.gnome.applets.WindowPicker.panel-applet.in.in \
	$(gsettings_file).in.in \
	$(service_in_files)

CLEANFILES = $(applet_DATA) $(applet_DATA).in $(service_DATA) $(gsettings_file).in $(gsettings_file)

