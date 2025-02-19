# Makefile for building LaTeX document with BibTeX

# Paths
OUTPUT_DIR = ./doc
SOURCE_DIR = ./src
DOC_NAME = TugasLaporanPostgreql
MAIN_FILE = $(SOURCE_DIR)/$(DOC_NAME).tex
OUTPUT_FILE = $(OUTPUT_DIR)/$(DOC_NAME).pdf
BIB_FILE = $(SOURCE_DIR)/$(DOC_NAME).bib

# Compiler and options
LATEX = pdflatex
BIBTEX = bibtex
LATEX_OPTS = -output-directory $(OUTPUT_DIR) -interaction=nonstopmode

# Default target: Build the document
all: $(OUTPUT_FILE)

# Build the PDF with BibTeX support
$(OUTPUT_FILE): $(MAIN_FILE)
	mkdir -p $(OUTPUT_DIR)
	$(LATEX) $(LATEX_OPTS) $<  # First LaTeX compilation
	$(BIBTEX) $(OUTPUT_DIR)/$(DOC_NAME) # Run BibTeX
	$(LATEX) $(LATEX_OPTS) $<  # Second LaTeX compilation to update references
	$(LATEX) $(LATEX_OPTS) $<  # Third LaTeX compilation for final fixes

# Clean intermediate files (auxiliary logs, etc.)
clean:
	rm -rf $(OUTPUT_DIR)/*.aux $(OUTPUT_DIR)/*.log $(OUTPUT_DIR)/*.toc \
	       $(OUTPUT_DIR)/*.out $(OUTPUT_DIR)/*.bbl $(OUTPUT_DIR)/*.blg \
	       $(OUTPUT_DIR)/*.lof $(OUTPUT_DIR)/*.lot

# Full clean, including generated PDF
distclean: clean
	rm -f $(OUTPUT_FILE)

# Preview the PDF (using xdg-open or your preferred viewer)
preview: $(OUTPUT_FILE)
	xdg-open $(OUTPUT_FILE) &

# Phony targets
.PHONY: all clean distclean preview

