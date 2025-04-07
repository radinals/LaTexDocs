
# Makefile for building LaTeX document

# Paths
OUTPUT_DIR = ./doc
SOURCE_DIR = ./src
DOC_NAME = TugasPraktikumWebDasar_3
MAIN_FILE = $(SOURCE_DIR)/$(DOC_NAME).tex
OUTPUT_FILE = $(OUTPUT_DIR)/$(DOC_NAME).pdf

# Compiler and options
LATEX = pdflatex
LATEX_OPTS = -output-directory $(OUTPUT_DIR) -interaction=nonstopmode

# Default target: Build the document
all: $(OUTPUT_FILE)

# Build the PDF
$(OUTPUT_FILE): $(MAIN_FILE)
	mkdir -p $(OUTPUT_DIR)
	$(LATEX) $(LATEX_OPTS) $< 
	$(LATEX) $(LATEX_OPTS) $< # Run twice to ensure references are resolved

# Clean intermediate files (auxiliary logs, etc.)
clean:
	rm -rf $(OUTPUT_DIR)/*.aux $(OUTPUT_DIR)/*.log $(OUTPUT_DIR)/*.toc $(OUTPUT_DIR)/*.out

# Full clean, including generated PDF
distclean: clean
	rm -f $(OUTPUT_FILE)

# Preview the PDF (using xdg-open or your preferred viewer)
preview: $(OUTPUT_FILE)
	xdg-open $(OUTPUT_FILE) &

# Phony targets
.PHONY: all clean distclean preview

