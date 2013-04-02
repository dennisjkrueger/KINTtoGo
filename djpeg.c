/*
The Independent JPEG Group's JPEG software
==========================================

README for release 6b of 27-Mar-1998
====================================

This distribution contains the sixth public release of the Independent JPEG
Group's free JPEG software.  You are welcome to redistribute this software and
to use it for any purpose, subject to the conditions under LEGAL ISSUES, below.

Serious users of this software (particularly those incorporating it into
larger programs) should contact IJG at jpeg-info@uunet.uu.net to be added to
our electronic mailing list.  Mailing list members are notified of updates
and have a chance to participate in technical discussions, etc.

This software is the work of Tom Lane, Philip Gladstone, Jim Boucher,
Lee Crocker, Julian Minguillon, Luis Ortiz, George Phillips, Davide Rossi,
Guido Vollbeding, Ge' Weijers, and other members of the Independent JPEG
Group.

IJG is not affiliated with the official ISO JPEG standards committee.


DOCUMENTATION ROADMAP
=====================

This file contains the following sections:

OVERVIEW            General description of JPEG and the IJG software.
LEGAL ISSUES        Copyright, lack of warranty, terms of distribution.
REFERENCES          Where to learn more about JPEG.
ARCHIVE LOCATIONS   Where to find newer versions of this software.
RELATED SOFTWARE    Other stuff you should get.
FILE FORMAT WARS    Software *not* to get.
TO DO               Plans for future IJG releases.

Other documentation files in the distribution are:

User documentation:
  install.doc       How to configure and install the IJG software.
  usage.doc         Usage instructions for cjpeg, djpeg, jpegtran,
                    rdjpgcom, and wrjpgcom.
  *.1               Unix-style man pages for programs (same info as usage.doc).
  wizard.doc        Advanced usage instructions for JPEG wizards only.
  change.log        Version-to-version change highlights.
Programmer and internal documentation:
  libjpeg.doc       How to use the JPEG library in your own programs.
  example.c         Sample code for calling the JPEG library.
  structure.doc     Overview of the JPEG library's internal structure.
  filelist.doc      Road map of IJG files.
  coderules.doc     Coding style rules --- please read if you contribute code.

Please read at least the files install.doc and usage.doc.  Useful information
can also be found in the JPEG FAQ (Frequently Asked Questions) article.  See
ARCHIVE LOCATIONS below to find out where to obtain the FAQ article.

If you want to understand how the JPEG code works, we suggest reading one or
more of the REFERENCES, then looking at the documentation files (in roughly
the order listed) before diving into the code.


OVERVIEW
========

This package contains C software to implement JPEG image compression and
decompression.  JPEG (pronounced "jay-peg") is a standardized compression
method for full-color and gray-scale images.  JPEG is intended for compressing
"real-world" scenes; line drawings, cartoons and other non-realistic images
are not its strong suit.  JPEG is lossy, meaning that the output image is not
exactly identical to the input image.  Hence you must not use JPEG if you
have to have identical output bits.  However, on typical photographic images,
very good compression levels can be obtained with no visible change, and
remarkably high compression levels are possible if you can tolerate a
low-quality image.  For more details, see the references, or just experiment
with various compression settings.

This software implements JPEG baseline, extended-sequential, and progressive
compression processes.  Provision is made for supporting all variants of these
processes, although some uncommon parameter settings aren't implemented yet.
For legal reasons, we are not distributing code for the arithmetic-coding
variants of JPEG; see LEGAL ISSUES.  We have made no provision for supporting
the hierarchical or lossless processes defined in the standard.

We provide a set of library routines for reading and writing JPEG image files,
plus two sample applications "cjpeg" and "djpeg", which use the library to
perform conversion between JPEG and some other popular image file formats.
The library is intended to be reused in other applications.

In order to support file conversion and viewing software, we have included
considerable functionality beyond the bare JPEG coding/decoding capability;
for example, the color quantization modules are not strictly part of JPEG
decoding, but they are essential for output to colormapped file formats or
colormapped displays.  These extra functions can be compiled out of the
library if not required for a particular application.  We have also included
"jpegtran", a utility for lossless transcoding between different JPEG
processes, and "rdjpgcom" and "wrjpgcom", two simple applications for
inserting and extracting textual comments in JFIF files.

The emphasis in designing this software has been on achieving portability and
flexibility, while also making it fast enough to be useful.  In particular,
the software is not intended to be read as a tutorial on JPEG.  (See the
REFERENCES section for introductory material.)  Rather, it is intended to
be reliable, portable, industrial-strength code.  We do not claim to have
achieved that goal in every aspect of the software, but we strive for it.

We welcome the use of this software as a component of commercial products.
No royalty is required, but we do ask for an acknowledgement in product
documentation, as described under LEGAL ISSUES.


LEGAL ISSUES
============

In plain English:

1. We don't promise that this software works.  (But if you find any bugs,
   please let us know!)
2. You can use this software for whatever you want.  You don't have to pay us.
3. You may not pretend that you wrote this software.  If you use it in a
   program, you must acknowledge somewhere in your documentation that
   you've used the IJG code.

In legalese:

The authors make NO WARRANTY or representation, either express or implied,
with respect to this software, its quality, accuracy, merchantability, or
fitness for a particular purpose.  This software is provided "AS IS", and you,
its user, assume the entire risk as to its quality and accuracy.

This software is copyright (C) 1991-1998, Thomas G. Lane.
All Rights Reserved except as specified below.

Permission is hereby granted to use, copy, modify, and distribute this
software (or portions thereof) for any purpose, without fee, subject to these
conditions:
(1) If any part of the source code for this software is distributed, then this
README file must be included, with this copyright and no-warranty notice
unaltered; and any additions, deletions, or changes to the original files
must be clearly indicated in accompanying documentation.
(2) If only executable code is distributed, then the accompanying
documentation must state that "this software is based in part on the work of
the Independent JPEG Group".
(3) Permission for use of this software is granted only if the user accepts
full responsibility for any undesirable consequences; the authors accept
NO LIABILITY for damages of any kind.

These conditions apply to any software derived from or based on the IJG code,
not just to the unmodified library.  If you use our work, you ought to
acknowledge us.

Permission is NOT granted for the use of any IJG author's name or company name
in advertising or publicity relating to this software or products derived from
it.  This software may be referred to only as "the Independent JPEG Group's
software".

We specifically permit and encourage the use of this software as the basis of
commercial products, provided that all warranty or liability claims are
assumed by the product vendor.


ansi2knr.c is included in this distribution by permission of L. Peter Deutsch,
sole proprietor of its copyright holder, Aladdin Enterprises of Menlo Park, CA.
ansi2knr.c is NOT covered by the above copyright and conditions, but instead
by the usual distribution terms of the Free Software Foundation; principally,
that you must include source code if you redistribute it.  (See the file
ansi2knr.c for full details.)  However, since ansi2knr.c is not needed as part
of any program generated from the IJG code, this does not limit you more than
the foregoing paragraphs do.

The Unix configuration script "configure" was produced with GNU Autoconf.
It is copyright by the Free Software Foundation but is freely distributable.
The same holds for its supporting scripts (config.guess, config.sub,
ltconfig, ltmain.sh).  Another support script, install-sh, is copyright
by M.I.T. but is also freely distributable.

It appears that the arithmetic coding option of the JPEG spec is covered by
patents owned by IBM, AT&T, and Mitsubishi.  Hence arithmetic coding cannot
legally be used without obtaining one or more licenses.  For this reason,
support for arithmetic coding has been removed from the free JPEG software.
(Since arithmetic coding provides only a marginal gain over the unpatented
Huffman mode, it is unlikely that very many implementations will support it.)
So far as we are aware, there are no patent restrictions on the remaining
code.

The IJG distribution formerly included code to read and write GIF files.
To avoid entanglement with the Unisys LZW patent, GIF reading support has
been removed altogether, and the GIF writer has been simplified to produce
"uncompressed GIFs".  This technique does not use the LZW algorithm; the
resulting GIF files are larger than usual, but are readable by all standard
GIF decoders.

We are required to state that
    "The Graphics Interchange Format(c) is the Copyright property of
    CompuServe Incorporated.  GIF(sm) is a Service Mark property of
    CompuServe Incorporated."


REFERENCES
==========

We highly recommend reading one or more of these references before trying to
understand the innards of the JPEG software.

The best short technical introduction to the JPEG compression algorithm is
	Wallace, Gregory K.  "The JPEG Still Picture Compression Standard",
	Communications of the ACM, April 1991 (vol. 34 no. 4), pp. 30-44.
(Adjacent articles in that issue discuss MPEG motion picture compression,
applications of JPEG, and related topics.)  If you don't have the CACM issue
handy, a PostScript file containing a revised version of Wallace's article is
available at ftp://ftp.uu.net/graphics/jpeg/wallace.ps.gz.  The file (actually
a preprint for an article that appeared in IEEE Trans. Consumer Electronics)
omits the sample images that appeared in CACM, but it includes corrections
and some added material.  Note: the Wallace article is copyright ACM and IEEE,
and it may not be used for commercial purposes.

A somewhat less technical, more leisurely introduction to JPEG can be found in
"The Data Compression Book" by Mark Nelson and Jean-loup Gailly, published by
M&T Books (New York), 2nd ed. 1996, ISBN 1-55851-434-1.  This book provides
good explanations and example C code for a multitude of compression methods
including JPEG.  It is an excellent source if you are comfortable reading C
code but don't know much about data compression in general.  The book's JPEG
sample code is far from industrial-strength, but when you are ready to look
at a full implementation, you've got one here...

The best full description of JPEG is the textbook "JPEG Still Image Data
Compression Standard" by William B. Pennebaker and Joan L. Mitchell, published
by Van Nostrand Reinhold, 1993, ISBN 0-442-01272-1.  Price US$59.95, 638 pp.
The book includes the complete text of the ISO JPEG standards (DIS 10918-1
and draft DIS 10918-2).  This is by far the most complete exposition of JPEG
in existence, and we highly recommend it.

The JPEG standard itself is not available electronically; you must order a
paper copy through ISO or ITU.  (Unless you feel a need to own a certified
official copy, we recommend buying the Pennebaker and Mitchell book instead;
it's much cheaper and includes a great deal of useful explanatory material.)
In the USA, copies of the standard may be ordered from ANSI Sales at (212)
642-4900, or from Global Engineering Documents at (800) 854-7179.  (ANSI
doesn't take credit card orders, but Global does.)  It's not cheap: as of
1992, ANSI was charging $95 for Part 1 and $47 for Part 2, plus 7%
shipping/handling.  The standard is divided into two parts, Part 1 being the
actual specification, while Part 2 covers compliance testing methods.  Part 1
is titled "Digital Compression and Coding of Continuous-tone Still Images,
Part 1: Requirements and guidelines" and has document numbers ISO/IEC IS
10918-1, ITU-T T.81.  Part 2 is titled "Digital Compression and Coding of
Continuous-tone Still Images, Part 2: Compliance testing" and has document
numbers ISO/IEC IS 10918-2, ITU-T T.83.

Some extensions to the original JPEG standard are defined in JPEG Part 3,
a newer ISO standard numbered ISO/IEC IS 10918-3 and ITU-T T.84.  IJG
currently does not support any Part 3 extensions.

The JPEG standard does not specify all details of an interchangeable file
format.  For the omitted details we follow the "JFIF" conventions, revision
1.02.  A copy of the JFIF spec is available from:
	Literature Department
	C-Cube Microsystems, Inc.
	1778 McCarthy Blvd.
	Milpitas, CA 95035
	phone (408) 944-6300,  fax (408) 944-6314
A PostScript version of this document is available by FTP at
ftp://ftp.uu.net/graphics/jpeg/jfif.ps.gz.  There is also a plain text
version at ftp://ftp.uu.net/graphics/jpeg/jfif.txt.gz, but it is missing
the figures.

The TIFF 6.0 file format specification can be obtained by FTP from
ftp://ftp.sgi.com/graphics/tiff/TIFF6.ps.gz.  The JPEG incorporation scheme
found in the TIFF 6.0 spec of 3-June-92 has a number of serious problems.
IJG does not recommend use of the TIFF 6.0 design (TIFF Compression tag 6).
Instead, we recommend the JPEG design proposed by TIFF Technical Note #2
(Compression tag 7).  Copies of this Note can be obtained from ftp.sgi.com or
from ftp://ftp.uu.net/graphics/jpeg/.  It is expected that the next revision
of the TIFF spec will replace the 6.0 JPEG design with the Note's design.
Although IJG's own code does not support TIFF/JPEG, the free libtiff library
uses our library to implement TIFF/JPEG per the Note.  libtiff is available
from ftp://ftp.sgi.com/graphics/tiff/.


ARCHIVE LOCATIONS
=================

The "official" archive site for this software is ftp.uu.net (Internet
address 192.48.96.9).  The most recent released version can always be found
there in directory graphics/jpeg.  This particular version will be archived
as ftp://ftp.uu.net/graphics/jpeg/jpegsrc.v6b.tar.gz.  If you don't have
direct Internet access, UUNET's archives are also available via UUCP; contact
help@uunet.uu.net for information on retrieving files that way.

Numerous Internet sites maintain copies of the UUNET files.  However, only
ftp.uu.net is guaranteed to have the latest official version.

You can also obtain this software in DOS-compatible "zip" archive format from
the SimTel archives (ftp://ftp.simtel.net/pub/simtelnet/msdos/graphics/), or
on CompuServe in the Graphics Support forum (GO CIS:GRAPHSUP), library 12
"JPEG Tools".  Again, these versions may sometimes lag behind the ftp.uu.net
release.

The JPEG FAQ (Frequently Asked Questions) article is a useful source of
general information about JPEG.  It is updated constantly and therefore is
not included in this distribution.  The FAQ is posted every two weeks to
Usenet newsgroups comp.graphics.misc, news.answers, and other groups.
It is available on the World Wide Web at http://www.faqs.org/faqs/jpeg-faq/
and other news.answers archive sites, including the official news.answers
archive at rtfm.mit.edu: ftp://rtfm.mit.edu/pub/usenet/news.answers/jpeg-faq/.
If you don't have Web or FTP access, send e-mail to mail-server@rtfm.mit.edu
with body
	send usenet/news.answers/jpeg-faq/part1
	send usenet/news.answers/jpeg-faq/part2


RELATED SOFTWARE
================

Numerous viewing and image manipulation programs now support JPEG.  (Quite a
few of them use this library to do so.)  The JPEG FAQ described above lists
some of the more popular free and shareware viewers, and tells where to
obtain them on Internet.

If you are on a Unix machine, we highly recommend Jef Poskanzer's free
PBMPLUS software, which provides many useful operations on PPM-format image
files.  In particular, it can convert PPM images to and from a wide range of
other formats, thus making cjpeg/djpeg considerably more useful.  The latest
version is distributed by the NetPBM group, and is available from numerous
sites, notably ftp://wuarchive.wustl.edu/graphics/graphics/packages/NetPBM/.
Unfortunately PBMPLUS/NETPBM is not nearly as portable as the IJG software is;
you are likely to have difficulty making it work on any non-Unix machine.

A different free JPEG implementation, written by the PVRG group at Stanford,
is available from ftp://havefun.stanford.edu/pub/jpeg/.  This program
is designed for research and experimentation rather than production use;
it is slower, harder to use, and less portable than the IJG code, but it
is easier to read and modify.  Also, the PVRG code supports lossless JPEG,
which we do not.  (On the other hand, it doesn't do progressive JPEG.)


FILE FORMAT WARS
================

Some JPEG programs produce files that are not compatible with our library.
The root of the problem is that the ISO JPEG committee failed to specify a
concrete file format.  Some vendors "filled in the blanks" on their own,
creating proprietary formats that no one else could read.  (For example, none
of the early commercial JPEG implementations for the Macintosh were able to
exchange compressed files.)

The file format we have adopted is called JFIF (see REFERENCES).  This format
has been agreed to by a number of major commercial JPEG vendors, and it has
become the de facto standard.  JFIF is a minimal or "low end" representation.
We recommend the use of TIFF/JPEG (TIFF revision 6.0 as modified by TIFF
Technical Note #2) for "high end" applications that need to record a lot of
additional data about an image.  TIFF/JPEG is fairly new and not yet widely
supported, unfortunately.

The upcoming JPEG Part 3 standard defines a file format called SPIFF.
SPIFF is interoperable with JFIF, in the sense that most JFIF decoders should
be able to read the most common variant of SPIFF.  SPIFF has some technical
advantages over JFIF, but its major claim to fame is simply that it is an
official standard rather than an informal one.  At this point it is unclear
whether SPIFF will supersede JFIF or whether JFIF will remain the de-facto
standard.  IJG intends to support SPIFF once the standard is frozen, but we
have not decided whether it should become our default output format or not.
(In any case, our decoder will remain capable of reading JFIF indefinitely.)

Various proprietary file formats incorporating JPEG compression also exist.
We have little or no sympathy for the existence of these formats.  Indeed,
one of the original reasons for developing this free software was to help
force convergence on common, open format standards for JPEG files.  Don't
use a proprietary file format!


TO DO
=====

The major thrust for v7 will probably be improvement of visual quality.
The current method for scaling the quantization tables is known not to be
very good at low Q values.  We also intend to investigate block boundary
smoothing, "poor man's variable quantization", and other means of improving
quality-vs-file-size performance without sacrificing compatibility.

In future versions, we are considering supporting some of the upcoming JPEG
Part 3 extensions --- principally, variable quantization and the SPIFF file
format.

As always, speeding things up is of great interest.

Please send bug reports, offers of help, etc. to jpeg-info@uunet.uu.net.
*/


#define JPEG_INTERNALS
#include "main.h"
#include "djpeg.h"		/* Common decls for cjpeg/djpeg applications */

PBMB	pX;	// global pointer to bitmap created for JPEG picture
BYTE	*pXbuf;

/*
 * jdapimin.c
 *
 * Copyright (C) 1994-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface code for the decompression half
 * of the JPEG library.  These are the "minimum" API routines that may be
 * needed in either the normal full-decompression case or the
 * transcoding-only case.
 *
 * Most of the routines intended to be called directly by an application
 * are in this file or in jdapistd.c.  But also see jcomapi.c for routines
 * shared by compression and decompression, and jdtrans.c for the transcoding
 * case.
 */

/*
 * Initialization of a JPEG decompression object.
 * The error manager must already be set up (in case memory manager fails).
 */

int jpeg_CreateDecompress (j_decompress_ptr cinfo, int version, size_t structsize)
{
  int i;

  /* Guard against version mismatches between library and caller. */
  cinfo->mem = NULL;		/* so jpeg_destroy knows mem mgr not called */

  /* For debugging purposes, we zero the whole master structure.
   * But the application has already set the err pointer, and may have set
   * client_data, so we have to save and restore those fields.
   * Note: if application hasn't set client_data, tools like Purify may
   * complain here.
   */
  {
    struct jpeg_error_mgr * err = cinfo->err;
    void * client_data = cinfo->client_data; /* ignore Purify complaint here */
    MEMZERO(cinfo, SIZEOF(struct jpeg_decompress_struct));
    cinfo->err = err;
    cinfo->client_data = client_data;
  }
  cinfo->is_decompressor = TRUE;

  /* Initialize a memory manager instance for this object */
  if( -1==jinit_memory_mgr((j_common_ptr) cinfo) ) return -1;

  /* Zero out pointers to permanent structures. */
  cinfo->src = NULL;

  for (i = 0; i < NUM_QUANT_TBLS; i++)
    cinfo->quant_tbl_ptrs[i] = NULL;

  for (i = 0; i < NUM_HUFF_TBLS; i++) {
    cinfo->dc_huff_tbl_ptrs[i] = NULL;
    cinfo->ac_huff_tbl_ptrs[i] = NULL;
  }

  /* Initialize marker processor so application can override methods
   * for COM, APPn markers before calling jpeg_read_header.
   */
  cinfo->marker_list = NULL;
  jinit_marker_reader(cinfo);

  /* And initialize the overall input controller. */
  jinit_input_controller(cinfo);

  /* OK, I'm ready */
  cinfo->global_state = DSTATE_START;

  return 0;
}


/*
 * Abort processing of a JPEG decompression operation,
 * but don't destroy the object itself.
 */

GLOBAL(void)
jpeg_abort_decompress (j_decompress_ptr cinfo)
{
  jpeg_abort((j_common_ptr) cinfo); /* use common routine */
}


/*
 * Set default decompression parameters.
 */

LOCAL(void)
default_decompress_parms (j_decompress_ptr cinfo)
{
  /* Guess the input colorspace, and set output colorspace accordingly. */
  /* (Wish JPEG committee had provided a real way to specify this...) */
  /* Note application may override our guesses. */
  switch (cinfo->num_components) {
  case 1:
    cinfo->jpeg_color_space = JCS_GRAYSCALE;
    break;
  case 3:
    if (cinfo->saw_JFIF_marker) {
      cinfo->jpeg_color_space = JCS_YCbCr; /* JFIF implies YCbCr */
    } else if (cinfo->saw_Adobe_marker) {
      switch (cinfo->Adobe_transform) {
      case 0:
		cinfo->jpeg_color_space = JCS_RGB;
		break;
      case 1:
		cinfo->jpeg_color_space = JCS_YCbCr;
		break;
      default:
		cinfo->jpeg_color_space = JCS_YCbCr; /* assume it's YCbCr */
		break;
      }
    } else {
      /* Saw no special markers, try to guess from the component IDs */
      int cid0 = cinfo->comp_info[0].component_id;
      int cid1 = cinfo->comp_info[1].component_id;
      int cid2 = cinfo->comp_info[2].component_id;

      if (cid0 == 1 && cid1 == 2 && cid2 == 3) cinfo->jpeg_color_space = JCS_YCbCr; /* assume JFIF w/out marker */
      else if (cid0 == 82 && cid1 == 71 && cid2 == 66) 	cinfo->jpeg_color_space = JCS_RGB; /* ASCII 'R', 'G', 'B' */
      else cinfo->jpeg_color_space = JCS_YCbCr; /* assume it's YCbCr */
    }
    break;
  case 4:
    if (cinfo->saw_Adobe_marker) {
      switch (cinfo->Adobe_transform) {
      case 0:
		cinfo->jpeg_color_space = JCS_CMYK;
		break;
      case 2:
		cinfo->jpeg_color_space = JCS_YCCK;
		break;
      default:
//	WARNMS1(cinfo, JWRN_ADOBE_XFORM, cinfo->Adobe_transform);
		cinfo->jpeg_color_space = JCS_YCCK; /* assume it's YCCK */
		break;
      }
    } else {
      /* No special markers, assume straight CMYK. */
      cinfo->jpeg_color_space = JCS_CMYK;
    }
    break;
  default:
    cinfo->jpeg_color_space = JCS_UNKNOWN;
    break;
  }

  /* Set defaults for other decompression parameters. */
  cinfo->scale_num = 1;		/* 1:1 scaling */
  cinfo->scale_denom = 1;
  cinfo->output_gamma = 1.0;
  cinfo->buffered_image = FALSE;
  cinfo->dct_method = JDCT_DEFAULT;
  cinfo->do_fancy_upsampling = TRUE;
  cinfo->do_block_smoothing = TRUE;
  /* We set these in case application only sets quantize_colors. */
  cinfo->colormap = NULL;
}


/*
 * Decompression startup: read start of JPEG datastream to see what's there.
 * Need only initialize JPEG object and supply a data source before calling.
 *
 * This routine will read as far as the first SOS marker (ie, actual start of
 * compressed data), and will save all tables and parameters in the JPEG
 * object.  It will also initialize the decompression parameters to default
 * values, and finally return JPEG_HEADER_OK.  On return, the application may
 * adjust the decompression parameters and then call jpeg_start_decompress.
 * (Or, if the application only wanted to determine the image parameters,
 * the data need not be decompressed.  In that case, call jpeg_abort or
 * jpeg_destroy to release any temporary space.)
 * If an abbreviated (tables only) datastream is presented, the routine will
 * return JPEG_HEADER_TABLES_ONLY upon reaching EOI.  The application may then
 * re-use the JPEG object to read the abbreviated image datastream(s).
 * It is unnecessary (but OK) to call jpeg_abort in this case.
 * The JPEG_SUSPENDED return code only occurs if the data source module
 * requests suspension of the decompressor.  In this case the application
 * should load more source data and then re-call jpeg_read_header to resume
 * processing.
 * If a non-suspending data source is used and require_image is TRUE, then the
 * return code need not be inspected since only JPEG_HEADER_OK is possible.
 *
 * This routine is now just a front end to jpeg_consume_input, with some
 * extra error checking.
 */

int jpeg_read_header (j_decompress_ptr cinfo) {

	int retcode;

	if( cinfo->global_state != DSTATE_START && cinfo->global_state != DSTATE_INHEADER ) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

	if( -1==(retcode = jpeg_consume_input(cinfo)) ) return -1;

	switch (retcode) {
	 case JPEG_REACHED_SOS:
		retcode = JPEG_HEADER_OK;
		break;
	 case JPEG_REACHED_EOI:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	 case JPEG_SUSPENDED:
	/* no work */
		break;
	}
	return retcode;
}


/*
 * Consume data in advance of what the decompressor requires.
 * This can be called at any time once the decompressor object has
 * been created and a data source has been set up.
 *
 * This routine is essentially a state machine that handles a couple
 * of critical state-transition actions, namely initial setup and
 * transition from header scanning to ready-for-start_decompress.
 * All the actual input is done via the input controller's consume_input
 * method.
 */

int jpeg_consume_input (j_decompress_ptr cinfo) {

	int retcode = JPEG_SUSPENDED;

	/* NB: every possible DSTATE value should be listed in this switch */
	switch (cinfo->global_state) {
	 case DSTATE_START:
		/* Start-of-datastream actions: reset appropriate modules */
		(*cinfo->inputctl->reset_input_controller) (cinfo);
		/* Initialize application's data source module */
		(*cinfo->src->init_source) (cinfo);
		cinfo->global_state = DSTATE_INHEADER;
		/*FALLTHROUGH*/
	 case DSTATE_INHEADER:
		retcode = (*cinfo->inputctl->consume_input) (cinfo);
		if( retcode == JPEG_REACHED_SOS ) { /* Found SOS, prepare to decompress */
			/* Set up default parameters based on header data */
			default_decompress_parms(cinfo);
			/* Set global state: ready for start_decompress */
			cinfo->global_state = DSTATE_READY;
		}
		break;
	 case DSTATE_READY:
		/* Can't advance past first SOS until start_decompress is called */
		retcode = JPEG_REACHED_SOS;
		break;
	 case DSTATE_PRELOAD:
	 case DSTATE_PRESCAN:
	 case DSTATE_SCANNING:
	 case DSTATE_RAW_OK:
	 case DSTATE_BUFIMAGE:
	 case DSTATE_BUFPOST:
	 case DSTATE_STOPPING:
		retcode = (*cinfo->inputctl->consume_input) (cinfo);
		break;
	 default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
	return retcode;
}


/*
 * Finish JPEG decompression.
 *
 * This will normally just verify the file trailer and release temp storage.
 *
 * Returns FALSE if suspended.  The return value need be inspected only if
 * a suspending data source is used.
 */

int jpeg_finish_decompress(j_decompress_ptr cinfo) {

	if( (cinfo->global_state == DSTATE_SCANNING || cinfo->global_state == DSTATE_RAW_OK) && ! cinfo->buffered_image) {
		/* Terminate final pass of non-buffered mode */
		if( cinfo->output_scanline < cinfo->output_height ) {
			jpeg_destroy((j_common_ptr)&cinfo);
			return -1;
		}
		(*cinfo->master->finish_output_pass) (cinfo);
		cinfo->global_state = DSTATE_STOPPING;
	} else if (cinfo->global_state == DSTATE_BUFIMAGE) {
		/* Finishing after a buffered-image operation */
		cinfo->global_state = DSTATE_STOPPING;
	} else if (cinfo->global_state != DSTATE_STOPPING) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
	/* Read until EOI */
	while (! cinfo->inputctl->eoi_reached) {
		if ((*cinfo->inputctl->consume_input) (cinfo) == JPEG_SUSPENDED) return FALSE;		/* Suspend, come back later */
	}
	/* We can use jpeg_abort to release memory and reset global_state */
	jpeg_abort((j_common_ptr) cinfo);
	return TRUE;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdapistd.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface code for the decompression half
 * of the JPEG library.  These are the "standard" API routines that are
 * used in the normal full-decompression case.  They are not used by a
 * transcoding-only application.  Note that if an application links in
 * jpeg_start_decompress, it will end up linking in the entire decompressor.
 * We thus must separate this file from jdapimin.c to avoid linking the
 * whole decompression library into a transcoder.
 */

/*
 * Decompression initialization.
 * jpeg_read_header must be completed before calling this.
 *
 * If a multipass operating mode was selected, this will do all but the
 * last pass, and thus may take a great deal of time.
 *
 * Returns FALSE if suspended.  The return value need be inspected only if
 * a suspending data source is used.
 */

int jpeg_start_decompress(j_decompress_ptr cinfo) {

	if (cinfo->global_state == DSTATE_READY) {
	/* First call: initialize master control, select active modules */
		jinit_master_decompress(cinfo);
		if( cinfo->buffered_image ) {
			/* No more work here; expecting jpeg_start_output next */
			cinfo->global_state = DSTATE_BUFIMAGE;
			return TRUE;
		}
		cinfo->global_state = DSTATE_PRELOAD;
	}
	if( cinfo->global_state == DSTATE_PRELOAD ) {
		/* If file has multiple scans, absorb them all into the coef buffer */
		if( cinfo->inputctl->has_multiple_scans ) {
			for (;;) {
				int retcode;

				/* Absorb some more input */
				retcode = (*cinfo->inputctl->consume_input) (cinfo);
				if( retcode == JPEG_SUSPENDED ) return FALSE;
				if( retcode == JPEG_REACHED_EOI ) break;
			}
		}
		cinfo->output_scan_number = cinfo->input_scan_number;
	} else if( cinfo->global_state != DSTATE_PRESCAN ) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
	/* Perform any dummy output passes, and set up for the final pass */

/*
 * Set up for an output pass, and perform any dummy pass(es) needed.
 * Common subroutine for jpeg_start_decompress.
 * Entry: global_state = DSTATE_PRESCAN only if previously suspended.
 * Exit: If done, returns TRUE and sets global_state for proper output mode.
 *       If suspended, returns FALSE and sets global_state = DSTATE_PRESCAN.
 */

  if (cinfo->global_state != DSTATE_PRESCAN) {
    /* First call: do pass setup */
    (*cinfo->master->prepare_for_output_pass) (cinfo);
    cinfo->output_scanline = 0;
    cinfo->global_state = DSTATE_PRESCAN;
  }
  /* Loop over any required dummy passes */
  while (cinfo->master->is_dummy_pass) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
  }
  /* Ready for application to drive output pass through
   * jpeg_read_scanlines.
   */
  cinfo->global_state = DSTATE_SCANNING;
  return TRUE;
}


/*
 * Read some scanlines of data from the JPEG decompressor.
 *
 * The return value will be the number of lines actually read.
 * This may be less than the number requested in several cases,
 * including bottom of image, data source suspension, and operating
 * modes that emit multiple scanlines at a time.
 *
 * Note: we warn about excess calls to jpeg_read_scanlines() since
 * this likely signals an application programmer error.  However,
 * an oversize buffer (max_lines > scanlines remaining) is not an error.
 */

JDIMENSION jpeg_read_scanlines(j_decompress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION max_lines) {

	JDIMENSION row_ctr;

	if (cinfo->global_state != DSTATE_SCANNING) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
	if( cinfo->output_scanline >= cinfo->output_height ) {
		//    WARNMS(cinfo, JWRN_TOO_MUCH_DATA);
		return 0;
	}

	/* Process some data */
	row_ctr = 0;
	(*cinfo->main->process_data) (cinfo, scanlines, &row_ctr, max_lines);
	cinfo->output_scanline += row_ctr;
	return row_ctr;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdatasrc.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains decompression data source routines for the case of
 * reading JPEG data from a file (or any stdio stream).  While these routines
 * are sufficient for most applications, some will want to use a different
 * source manager.
 * IMPORTANT: we assume that fread() will correctly transcribe an array of
 * JOCTETs from 8-bit-wide elements on external storage.  If char is wider
 * than 8 bits on your machine, you may need to do some tweaking.
 */

/* this is not a core library module, so it doesn't define JPEG_INTERNALS */

/* Expanded data source object for stdio input */

typedef struct {
  struct jpeg_source_mgr pub;	/* public fields */

  DWORD infile;		/* source file */
  JOCTET * buffer;		/* start of buffer */
  boolean start_of_file;	/* have we gotten any data yet? */
} my_source_mgr;

typedef my_source_mgr * my_src_ptr;

#define INPUT_BUF_SIZE  4096	/* choose an efficiently fread'able size */


/*
 * Initialize source --- called by jpeg_read_header
 * before any data is actually read.
 */

METHODDEF(void)
init_source (j_decompress_ptr cinfo)
{
  my_src_ptr src = (my_src_ptr) cinfo->src;

  /* We reset the empty-input-file flag for each image,
   * but we don't clear the input buffer.
   * This is correct behavior for reading a series of images from one source.
   */
  src->start_of_file = TRUE;
}


/*
 * Fill the input buffer --- called whenever buffer is emptied.
 *
 * In typical applications, this should read fresh data into the buffer
 * (ignoring the current state of next_input_byte & bytes_in_buffer),
 * reset the pointer & count to the start of the buffer, and return TRUE
 * indicating that the buffer has been reloaded.  It is not necessary to
 * fill the buffer entirely, only to obtain at least one more byte.
 *
 * There is no such thing as an EOF return.  If the end of the file has been
 * reached, the routine has a choice of ERREXIT() or inserting fake data into
 * the buffer.  In most cases, generating a warning message and inserting a
 * fake EOI marker is the best course of action --- this will allow the
 * decompressor to output however much of the image is there.  However,
 * the resulting error message is misleading if the real problem is an empty
 * input file, so we handle that case specially.
 *
 * In applications that need to be able to suspend compression due to input
 * not being available yet, a FALSE return indicates that no more data can be
 * obtained right now, but more may be forthcoming later.  In this situation,
 * the decompressor will return to its caller (with an indication of the
 * number of scanlines it has read, if any).  The application should resume
 * decompression after it has loaded more data into the input buffer.  Note
 * that there are substantial restrictions on the use of suspension --- see
 * the documentation.
 *
 * When suspending, the decompressor will back up to a convenient restart point
 * (typically the start of the current MCU). next_input_byte & bytes_in_buffer
 * indicate where the restart point will be if the current call returns FALSE.
 * Data beyond this point must be rescanned after resumption, so move it to
 * the front of the buffer rather than discarding it.
 */


int fill_input_buffer (j_decompress_ptr cinfo) {

  my_src_ptr src = (my_src_ptr) cinfo->src;
  size_t nbytes;

//#define JFREAD(file,buf,sizeofbuf) ((size_t) fread((void *) (buf), (size_t) 1, (size_t) (sizeofbuf), (file)))
  nbytes = (size_t)Kread(src->infile, src->buffer, INPUT_BUF_SIZE);
//  nbytes = fread(src->buffer, 1, INPUT_BUF_SIZE, src->infile);
//  nbytes = JFREAD(src->infile, src->buffer, INPUT_BUF_SIZE);

  if (nbytes <= 0) {
   		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;

//	}
//    WARNMS(cinfo, JWRN_JPEG_EOF);
    /* Insert a fake EOI marker */
//    src->buffer[0] = (JOCTET) 0xFF;
//    src->buffer[1] = (JOCTET) JPEG_EOI;
//    nbytes = 2;
  }

  src->pub.next_input_byte = src->buffer;
  src->pub.bytes_in_buffer = nbytes;
  src->start_of_file = FALSE;

  return TRUE;
}


/*
 * Skip data --- used to skip over a potentially large amount of
 * uninteresting data (such as an APPn marker).
 *
 * Writers of suspendable-input applications must note that skip_input_data
 * is not granted the right to give a suspension return.  If the skip extends
 * beyond the data currently in the buffer, the buffer can be marked empty so
 * that the next read will cause a fill_input_buffer call that can suspend.
 * Arranging for additional bytes to be discarded before reloading the input
 * buffer is the application writer's problem.
 */

int skip_input_data (j_decompress_ptr cinfo, long num_bytes) {

  my_src_ptr src = (my_src_ptr) cinfo->src;

  /* Just a dumb implementation for now.  Could use fseek() except
   * it doesn't work on pipes.  Not clear that being smart is worth
   * any trouble anyway --- large skips are infrequent.
   */
  if (num_bytes > 0) {
    while (num_bytes > (long) src->pub.bytes_in_buffer) {
      num_bytes -= (long) src->pub.bytes_in_buffer;
      if( -1==fill_input_buffer(cinfo) ) return -1;
      /* note we assume that fill_input_buffer will never return FALSE,
       * so suspension need not be handled.
       */
    }
    src->pub.next_input_byte += (size_t) num_bytes;
    src->pub.bytes_in_buffer -= (size_t) num_bytes;
  }
  return 0;
}


/*
 * An additional method that can be provided by data source modules is the
 * resync_to_restart method for error recovery in the presence of RST markers.
 * For the moment, this source module just uses the default resync method
 * provided by the JPEG library.  That method assumes that no backtracking
 * is possible.
 */


/*
 * Prepare for input from a stdio stream.
 * The caller must have already opened the stream, and is responsible
 * for closing it after finishing decompression.
 */

GLOBAL(void)
jpeg_stdio_src (j_decompress_ptr cinfo, DWORD infile)
{
  my_src_ptr src;

  /* The source object and input buffer are made permanent so that a series
   * of JPEG images can be read from the same file by calling jpeg_stdio_src
   * only before the first one.  (If we discarded the buffer at the end of
   * one image, we'd likely lose the start of the next one.)
   * This makes it unsafe to use this manager and a different source
   * manager serially with the same JPEG object.  Caveat programmer.
   */
  if (cinfo->src == NULL) {	/* first time for this JPEG object? */
    cinfo->src = (struct jpeg_source_mgr *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
				  SIZEOF(my_source_mgr));
    src = (my_src_ptr) cinfo->src;
    src->buffer = (JOCTET *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
				  INPUT_BUF_SIZE * SIZEOF(JOCTET));
  }

  src = (my_src_ptr) cinfo->src;
  src->pub.init_source = init_source;
  src->pub.fill_input_buffer = fill_input_buffer;
  src->pub.skip_input_data = skip_input_data;
  src->pub.resync_to_restart = jpeg_resync_to_restart; /* use default method */
  src->infile = infile;
  src->pub.bytes_in_buffer = 0; /* forces fill_input_buffer on first read */
  src->pub.next_input_byte = NULL; /* until buffer loaded */
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdcoefct.c
 *
 * Copyright (C) 1994-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the coefficient buffer controller for decompression.
 * This controller is the top level of the JPEG decompressor proper.
 * The coefficient buffer lies between entropy decoding and inverse-DCT steps.
 *
 * In buffered-image mode, this controller is the interface between
 * input-oriented processing and output-oriented processing.
 * Also, the input side (only) is used when reading a file for transcoding.
 */

/* Block smoothing is only applicable for progressive JPEG, so: */
#ifndef D_PROGRESSIVE_SUPPORTED
#undef BLOCK_SMOOTHING_SUPPORTED
#endif

/* Private buffer controller object */

typedef struct {
  struct jpeg_d_coef_controller pub; /* public fields */

  /* These variables keep track of the current location of the input side. */
  /* cinfo->input_iMCU_row is also used for this. */
  JDIMENSION MCU_ctr;		/* counts MCUs processed in current row */
  int MCU_vert_offset;		/* counts MCU rows within iMCU row */
  int MCU_rows_per_iMCU_row;	/* number of such rows needed */

  /* The output side's location is represented by cinfo->output_iMCU_row. */

  /* In single-pass modes, it's sufficient to buffer just one MCU.
   * We allocate a workspace of D_MAX_BLOCKS_IN_MCU coefficient blocks,
   * and let the entropy decoder write into that workspace each time.
   * (On 80x86, the workspace is FAR even though it's not really very big;
   * this is to keep the module interfaces unchanged when a large coefficient
   * buffer is necessary.)
   * In multi-pass modes, this array points to the current MCU's blocks
   * within the virtual arrays; it is used only by the input side.
   */
  JBLOCKROW MCU_buffer[D_MAX_BLOCKS_IN_MCU];

#ifdef D_MULTISCAN_FILES_SUPPORTED
  /* In multi-pass modes, we need a virtual block array for each component. */
  jvirt_barray_ptr whole_image[MAX_COMPONENTS];
#endif

#ifdef BLOCK_SMOOTHING_SUPPORTED
  /* When doing block smoothing, we latch coefficient Al values here */
  int * coef_bits_latch;
#define SAVED_COEFS  6		/* we save coef_bits[0..5] */
#endif
} my_coef_controller;

typedef my_coef_controller * my_coef_ptr;

/* Forward declarations */
METHODDEF(int) decompress_onepass
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#ifdef D_MULTISCAN_FILES_SUPPORTED
METHODDEF(int) decompress_data
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#endif
#ifdef BLOCK_SMOOTHING_SUPPORTED
LOCAL(boolean) smoothing_ok JPP((j_decompress_ptr cinfo));
METHODDEF(int) decompress_smooth_data
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#endif


LOCAL(void)
start_iMCU_row (j_decompress_ptr cinfo)
/* Reset within-iMCU-row counters for a new row (input side) */
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;

  /* In an interleaved scan, an MCU row is the same as an iMCU row.
   * In a noninterleaved scan, an iMCU row has v_samp_factor MCU rows.
   * But at the bottom of the image, process only what's left.
   */
  if (cinfo->comps_in_scan > 1) {
    coef->MCU_rows_per_iMCU_row = 1;
  } else {
    if (cinfo->input_iMCU_row < (cinfo->total_iMCU_rows-1))
      coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->v_samp_factor;
    else
      coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->last_row_height;
  }

  coef->MCU_ctr = 0;
  coef->MCU_vert_offset = 0;
}


/*
 * Initialize for an input processing pass.
 */

int Cstart_input_pass (j_decompress_ptr cinfo) {

	cinfo->input_iMCU_row = 0;
	start_iMCU_row(cinfo);
	return 0;
}


/*
 * Initialize for an output processing pass.
 */

METHODDEF(void)
start_output_pass (j_decompress_ptr cinfo)
{
#ifdef BLOCK_SMOOTHING_SUPPORTED
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;

  /* If multipass, check to see whether to use block smoothing on this pass */
  if (coef->pub.coef_arrays != NULL) {
    if (cinfo->do_block_smoothing && smoothing_ok(cinfo))
      coef->pub.decompress_data = decompress_smooth_data;
    else
      coef->pub.decompress_data = decompress_data;
  }
#endif
  cinfo->output_iMCU_row = 0;
}


/*
 * Decompress and return some data in the single-pass case.
 * Always attempts to emit one fully interleaved MCU row ("iMCU" row).
 * Input and output must run in lockstep since we have only a one-MCU buffer.
 * Return value is JPEG_ROW_COMPLETED, JPEG_SCAN_COMPLETED, or JPEG_SUSPENDED.
 *
 * NB: output_buf contains a plane for each component in image,
 * which we index according to the component's SOF position.
 */

METHODDEF(int)
decompress_onepass (j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;
  JDIMENSION MCU_col_num;	/* index of current MCU within row */
  JDIMENSION last_MCU_col = cinfo->MCUs_per_row - 1;
  JDIMENSION last_iMCU_row = cinfo->total_iMCU_rows - 1;
  int blkn, ci, xindex, yindex, yoffset, useful_width;
  JSAMPARRAY output_ptr;
  JDIMENSION start_col, output_col;
  jpeg_component_info *compptr;
  inverse_DCT_method_ptr inverse_DCT;

  /* Loop to process as much as one whole iMCU row */
  for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row;
       yoffset++) {
    for (MCU_col_num = coef->MCU_ctr; MCU_col_num <= last_MCU_col;
	 MCU_col_num++) {
      /* Try to fetch an MCU.  Entropy decoder expects buffer to be zeroed. */
      jzero_far((void  *) coef->MCU_buffer[0],
		(size_t) (cinfo->blocks_in_MCU * SIZEOF(JBLOCK)));
      if (! (*cinfo->entropy->decode_mcu) (cinfo, coef->MCU_buffer)) {
	/* Suspension forced; update state counters and exit */
	coef->MCU_vert_offset = yoffset;
	coef->MCU_ctr = MCU_col_num;
	return JPEG_SUSPENDED;
      }
      /* Determine where data should go in output_buf and do the IDCT thing.
       * We skip dummy blocks at the right and bottom edges (but blkn gets
       * incremented past them!).  Note the inner loop relies on having
       * allocated the MCU_buffer[] blocks sequentially.
       */
      blkn = 0;			/* index of current DCT block within MCU */
      for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
	compptr = cinfo->cur_comp_info[ci];
	/* Don't bother to IDCT an uninteresting component. */
	if (! compptr->component_needed) {
	  blkn += compptr->MCU_blocks;
	  continue;
	}
	inverse_DCT = cinfo->idct->inverse_DCT[compptr->component_index];
	useful_width = (MCU_col_num < last_MCU_col) ? compptr->MCU_width
						    : compptr->last_col_width;
	output_ptr = output_buf[compptr->component_index] +
	  yoffset * compptr->DCT_scaled_size;
	start_col = MCU_col_num * compptr->MCU_sample_width;
	for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
	  if (cinfo->input_iMCU_row < last_iMCU_row ||
	      yoffset+yindex < compptr->last_row_height) {
	    output_col = start_col;
	    for (xindex = 0; xindex < useful_width; xindex++) {
	      (*inverse_DCT) (cinfo, compptr,
			      (JCOEFPTR) coef->MCU_buffer[blkn+xindex],
			      output_ptr, output_col);
	      output_col += compptr->DCT_scaled_size;
	    }
	  }
	  blkn += compptr->MCU_width;
	  output_ptr += compptr->DCT_scaled_size;
	}
      }
    }
    /* Completed an MCU row, but perhaps not an iMCU row */
    coef->MCU_ctr = 0;
  }
  /* Completed the iMCU row, advance counters for next one */
  cinfo->output_iMCU_row++;
  if (++(cinfo->input_iMCU_row) < cinfo->total_iMCU_rows) {
    start_iMCU_row(cinfo);
    return JPEG_ROW_COMPLETED;
  }
  /* Completed the scan */
  (*cinfo->inputctl->finish_input_pass) (cinfo);
  return JPEG_SCAN_COMPLETED;
}


/*
 * Dummy consume-input routine for single-pass operation.
 */

METHODDEF(int)
dummy_consume_data (j_decompress_ptr cinfo)
{
  return JPEG_SUSPENDED;	/* Always indicate nothing was done */
}


#ifdef D_MULTISCAN_FILES_SUPPORTED

/*
 * Consume input data and store it in the full-image coefficient buffer.
 * We read as much as one fully interleaved MCU row ("iMCU" row) per call,
 * ie, v_samp_factor block rows for each component in the scan.
 * Return value is JPEG_ROW_COMPLETED, JPEG_SCAN_COMPLETED, or JPEG_SUSPENDED.
 */

METHODDEF(int)
consume_data (j_decompress_ptr cinfo)
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;
  JDIMENSION MCU_col_num;	/* index of current MCU within row */
  int blkn, ci, xindex, yindex, yoffset;
  JDIMENSION start_col;
  JBLOCKARRAY buffer[MAX_COMPS_IN_SCAN];
  JBLOCKROW buffer_ptr;
  jpeg_component_info *compptr;

  /* Align the virtual buffers for the components used in this scan. */
  for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
    compptr = cinfo->cur_comp_info[ci];
    buffer[ci] = (*cinfo->mem->access_virt_barray)
      ((j_common_ptr) cinfo, coef->whole_image[compptr->component_index],
       cinfo->input_iMCU_row * compptr->v_samp_factor,
       (JDIMENSION) compptr->v_samp_factor, TRUE);
    /* Note: entropy decoder expects buffer to be zeroed,
     * but this is handled automatically by the memory manager
     * because we requested a pre-zeroed array.
     */
  }

  /* Loop to process one whole iMCU row */
  for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row;
       yoffset++) {
    for (MCU_col_num = coef->MCU_ctr; MCU_col_num < cinfo->MCUs_per_row;
	 MCU_col_num++) {
      /* Construct list of pointers to DCT blocks belonging to this MCU */
      blkn = 0;			/* index of current DCT block within MCU */
      for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
	compptr = cinfo->cur_comp_info[ci];
	start_col = MCU_col_num * compptr->MCU_width;
	for (yindex = 0; yindex < compptr->MCU_height; yindex++) {
	  buffer_ptr = buffer[ci][yindex+yoffset] + start_col;
	  for (xindex = 0; xindex < compptr->MCU_width; xindex++) {
	    coef->MCU_buffer[blkn++] = buffer_ptr++;
	  }
	}
      }
      /* Try to fetch the MCU. */
      if (! (*cinfo->entropy->decode_mcu) (cinfo, coef->MCU_buffer)) {
	/* Suspension forced; update state counters and exit */
	coef->MCU_vert_offset = yoffset;
	coef->MCU_ctr = MCU_col_num;
	return JPEG_SUSPENDED;
      }
    }
    /* Completed an MCU row, but perhaps not an iMCU row */
    coef->MCU_ctr = 0;
  }
  /* Completed the iMCU row, advance counters for next one */
  if (++(cinfo->input_iMCU_row) < cinfo->total_iMCU_rows) {
    start_iMCU_row(cinfo);
    return JPEG_ROW_COMPLETED;
  }
  /* Completed the scan */
  (*cinfo->inputctl->finish_input_pass) (cinfo);
  return JPEG_SCAN_COMPLETED;
}


/*
 * Decompress and return some data in the multi-pass case.
 * Always attempts to emit one fully interleaved MCU row ("iMCU" row).
 * Return value is JPEG_ROW_COMPLETED, JPEG_SCAN_COMPLETED, or JPEG_SUSPENDED.
 *
 * NB: output_buf contains a plane for each component in image.
 */

METHODDEF(int)
decompress_data (j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;
  JDIMENSION last_iMCU_row = cinfo->total_iMCU_rows - 1;
  JDIMENSION block_num;
  int ci, block_row, block_rows;
  JBLOCKARRAY buffer;
  JBLOCKROW buffer_ptr;
  JSAMPARRAY output_ptr;
  JDIMENSION output_col;
  jpeg_component_info *compptr;
  inverse_DCT_method_ptr inverse_DCT;

  /* Force some input to be done if we are getting ahead of the input. */
  while (cinfo->input_scan_number < cinfo->output_scan_number ||
	 (cinfo->input_scan_number == cinfo->output_scan_number &&
	  cinfo->input_iMCU_row <= cinfo->output_iMCU_row)) {
    if ((*cinfo->inputctl->consume_input)(cinfo) == JPEG_SUSPENDED)
      return JPEG_SUSPENDED;
  }

  /* OK, output from the virtual arrays. */
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Don't bother to IDCT an uninteresting component. */
    if (! compptr->component_needed)
      continue;
    /* Align the virtual buffer for this component. */
    buffer = (*cinfo->mem->access_virt_barray)
      ((j_common_ptr) cinfo, coef->whole_image[ci],
       cinfo->output_iMCU_row * compptr->v_samp_factor,
       (JDIMENSION) compptr->v_samp_factor, FALSE);
    /* Count non-dummy DCT block rows in this iMCU row. */
    if (cinfo->output_iMCU_row < last_iMCU_row)
      block_rows = compptr->v_samp_factor;
    else {
      /* NB: can't use last_row_height here; it is input-side-dependent! */
      block_rows = (int) (compptr->height_in_blocks % compptr->v_samp_factor);
      if (block_rows == 0) block_rows = compptr->v_samp_factor;
    }
    inverse_DCT = cinfo->idct->inverse_DCT[ci];
    output_ptr = output_buf[ci];
    /* Loop over all DCT blocks to be processed. */
    for (block_row = 0; block_row < block_rows; block_row++) {
      buffer_ptr = buffer[block_row];
      output_col = 0;
      for (block_num = 0; block_num < compptr->width_in_blocks; block_num++) {
	(*inverse_DCT) (cinfo, compptr, (JCOEFPTR) buffer_ptr,
			output_ptr, output_col);
	buffer_ptr++;
	output_col += compptr->DCT_scaled_size;
      }
      output_ptr += compptr->DCT_scaled_size;
    }
  }

  if (++(cinfo->output_iMCU_row) < cinfo->total_iMCU_rows)
    return JPEG_ROW_COMPLETED;
  return JPEG_SCAN_COMPLETED;
}

#endif /* D_MULTISCAN_FILES_SUPPORTED */


#ifdef BLOCK_SMOOTHING_SUPPORTED

/*
 * This code applies interblock smoothing as described by section K.8
 * of the JPEG standard: the first 5 AC coefficients are estimated from
 * the DC values of a DCT block and its 8 neighboring blocks.
 * We apply smoothing only for progressive JPEG decoding, and only if
 * the coefficients it can estimate are not yet known to full precision.
 */

/* Natural-order array positions of the first 5 zigzag-order coefficients */
#define Q01_POS  1
#define Q10_POS  8
#define Q20_POS  16
#define Q11_POS  9
#define Q02_POS  2

/*
 * Determine whether block smoothing is applicable and safe.
 * We also latch the current states of the coef_bits[] entries for the
 * AC coefficients; otherwise, if the input side of the decompressor
 * advances into a new scan, we might think the coefficients are known
 * more accurately than they really are.
 */

LOCAL(boolean)
smoothing_ok (j_decompress_ptr cinfo)
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;
  boolean smoothing_useful = FALSE;
  int ci, coefi;
  jpeg_component_info *compptr;
  JQUANT_TBL * qtable;
  int * coef_bits;
  int * coef_bits_latch;

  if (! cinfo->progressive_mode || cinfo->coef_bits == NULL)
    return FALSE;

  /* Allocate latch area if not already done */
  if (coef->coef_bits_latch == NULL)
    coef->coef_bits_latch = (int *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  cinfo->num_components *
				  (SAVED_COEFS * SIZEOF(int)));
  coef_bits_latch = coef->coef_bits_latch;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* All components' quantization values must already be latched. */
    if ((qtable = compptr->quant_table) == NULL)
      return FALSE;
    /* Verify DC & first 5 AC quantizers are nonzero to avoid zero-divide. */
    if (qtable->quantval[0] == 0 ||
	qtable->quantval[Q01_POS] == 0 ||
	qtable->quantval[Q10_POS] == 0 ||
	qtable->quantval[Q20_POS] == 0 ||
	qtable->quantval[Q11_POS] == 0 ||
	qtable->quantval[Q02_POS] == 0)
      return FALSE;
    /* DC values must be at least partly known for all components. */
    coef_bits = cinfo->coef_bits[ci];
    if (coef_bits[0] < 0)
      return FALSE;
    /* Block smoothing is helpful if some AC coefficients remain inaccurate. */
    for (coefi = 1; coefi <= 5; coefi++) {
      coef_bits_latch[coefi] = coef_bits[coefi];
      if (coef_bits[coefi] != 0)
	smoothing_useful = TRUE;
    }
    coef_bits_latch += SAVED_COEFS;
  }

  return smoothing_useful;
}


/*
 * Variant of decompress_data for use when doing block smoothing.
 */

METHODDEF(int)
decompress_smooth_data (j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;
  JDIMENSION last_iMCU_row = cinfo->total_iMCU_rows - 1;
  JDIMENSION block_num, last_block_column;
  int ci, block_row, block_rows, access_rows;
  JBLOCKARRAY buffer;
  JBLOCKROW buffer_ptr, prev_block_row, next_block_row;
  JSAMPARRAY output_ptr;
  JDIMENSION output_col;
  jpeg_component_info *compptr;
  inverse_DCT_method_ptr inverse_DCT;
  boolean first_row, last_row;
  JBLOCK workspace;
  int *coef_bits;
  JQUANT_TBL *quanttbl;
  INT32 Q00,Q01,Q02,Q10,Q11,Q20, num;
  int DC1,DC2,DC3,DC4,DC5,DC6,DC7,DC8,DC9;
  int Al, pred;

  /* Force some input to be done if we are getting ahead of the input. */
  while (cinfo->input_scan_number <= cinfo->output_scan_number &&
	 ! cinfo->inputctl->eoi_reached) {
    if (cinfo->input_scan_number == cinfo->output_scan_number) {
      /* If input is working on current scan, we ordinarily want it to
       * have completed the current row.  But if input scan is DC,
       * we want it to keep one row ahead so that next block row's DC
       * values are up to date.
       */
      JDIMENSION delta = (cinfo->Ss == 0) ? 1 : 0;
      if (cinfo->input_iMCU_row > cinfo->output_iMCU_row+delta)
	break;
    }
    if ((*cinfo->inputctl->consume_input)(cinfo) == JPEG_SUSPENDED)
      return JPEG_SUSPENDED;
  }

  /* OK, output from the virtual arrays. */
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Don't bother to IDCT an uninteresting component. */
    if (! compptr->component_needed)
      continue;
    /* Count non-dummy DCT block rows in this iMCU row. */
    if (cinfo->output_iMCU_row < last_iMCU_row) {
      block_rows = compptr->v_samp_factor;
      access_rows = block_rows * 2; /* this and next iMCU row */
      last_row = FALSE;
    } else {
      /* NB: can't use last_row_height here; it is input-side-dependent! */
      block_rows = (int) (compptr->height_in_blocks % compptr->v_samp_factor);
      if (block_rows == 0) block_rows = compptr->v_samp_factor;
      access_rows = block_rows; /* this iMCU row only */
      last_row = TRUE;
    }
    /* Align the virtual buffer for this component. */
    if (cinfo->output_iMCU_row > 0) {
      access_rows += compptr->v_samp_factor; /* prior iMCU row too */
      buffer = (*cinfo->mem->access_virt_barray)
	((j_common_ptr) cinfo, coef->whole_image[ci],
	 (cinfo->output_iMCU_row - 1) * compptr->v_samp_factor,
	 (JDIMENSION) access_rows, FALSE);
      buffer += compptr->v_samp_factor;	/* point to current iMCU row */
      first_row = FALSE;
    } else {
      buffer = (*cinfo->mem->access_virt_barray)
	((j_common_ptr) cinfo, coef->whole_image[ci],
	 (JDIMENSION) 0, (JDIMENSION) access_rows, FALSE);
      first_row = TRUE;
    }
    /* Fetch component-dependent info */
    coef_bits = coef->coef_bits_latch + (ci * SAVED_COEFS);
    quanttbl = compptr->quant_table;
    Q00 = quanttbl->quantval[0];
    Q01 = quanttbl->quantval[Q01_POS];
    Q10 = quanttbl->quantval[Q10_POS];
    Q20 = quanttbl->quantval[Q20_POS];
    Q11 = quanttbl->quantval[Q11_POS];
    Q02 = quanttbl->quantval[Q02_POS];
    inverse_DCT = cinfo->idct->inverse_DCT[ci];
    output_ptr = output_buf[ci];
    /* Loop over all DCT blocks to be processed. */
    for (block_row = 0; block_row < block_rows; block_row++) {
      buffer_ptr = buffer[block_row];
      if (first_row && block_row == 0)
	prev_block_row = buffer_ptr;
      else
	prev_block_row = buffer[block_row-1];
      if (last_row && block_row == block_rows-1)
	next_block_row = buffer_ptr;
      else
	next_block_row = buffer[block_row+1];
      /* We fetch the surrounding DC values using a sliding-register approach.
       * Initialize all nine here so as to do the right thing on narrow pics.
       */
      DC1 = DC2 = DC3 = (int) prev_block_row[0][0];
      DC4 = DC5 = DC6 = (int) buffer_ptr[0][0];
      DC7 = DC8 = DC9 = (int) next_block_row[0][0];
      output_col = 0;
      last_block_column = compptr->width_in_blocks - 1;
      for (block_num = 0; block_num <= last_block_column; block_num++) {
	/* Fetch current DCT block into workspace so we can modify it. */
	jcopy_block_row(buffer_ptr, (JBLOCKROW) workspace, (JDIMENSION) 1);
	/* Update DC values */
	if (block_num < last_block_column) {
	  DC3 = (int) prev_block_row[1][0];
	  DC6 = (int) buffer_ptr[1][0];
	  DC9 = (int) next_block_row[1][0];
	}
	/* Compute coefficient estimates per K.8.
	 * An estimate is applied only if coefficient is still zero,
	 * and is not known to be fully accurate.
	 */
	/* AC01 */
	if ((Al=coef_bits[1]) != 0 && workspace[1] == 0) {
	  num = 36 * Q00 * (DC4 - DC6);
	  if (num >= 0) {
	    pred = (int) (((Q01<<7) + num) / (Q01<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	  } else {
	    pred = (int) (((Q01<<7) - num) / (Q01<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	    pred = -pred;
	  }
	  workspace[1] = (JCOEF) pred;
	}
	/* AC10 */
	if ((Al=coef_bits[2]) != 0 && workspace[8] == 0) {
	  num = 36 * Q00 * (DC2 - DC8);
	  if (num >= 0) {
	    pred = (int) (((Q10<<7) + num) / (Q10<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	  } else {
	    pred = (int) (((Q10<<7) - num) / (Q10<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	    pred = -pred;
	  }
	  workspace[8] = (JCOEF) pred;
	}
	/* AC20 */
	if ((Al=coef_bits[3]) != 0 && workspace[16] == 0) {
	  num = 9 * Q00 * (DC2 + DC8 - 2*DC5);
	  if (num >= 0) {
	    pred = (int) (((Q20<<7) + num) / (Q20<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	  } else {
	    pred = (int) (((Q20<<7) - num) / (Q20<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	    pred = -pred;
	  }
	  workspace[16] = (JCOEF) pred;
	}
	/* AC11 */
	if ((Al=coef_bits[4]) != 0 && workspace[9] == 0) {
	  num = 5 * Q00 * (DC1 - DC3 - DC7 + DC9);
	  if (num >= 0) {
	    pred = (int) (((Q11<<7) + num) / (Q11<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	  } else {
	    pred = (int) (((Q11<<7) - num) / (Q11<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	    pred = -pred;
	  }
	  workspace[9] = (JCOEF) pred;
	}
	/* AC02 */
	if ((Al=coef_bits[5]) != 0 && workspace[2] == 0) {
	  num = 9 * Q00 * (DC4 + DC6 - 2*DC5);
	  if (num >= 0) {
	    pred = (int) (((Q02<<7) + num) / (Q02<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	  } else {
	    pred = (int) (((Q02<<7) - num) / (Q02<<8));
	    if (Al > 0 && pred >= (1<<Al))
	      pred = (1<<Al)-1;
	    pred = -pred;
	  }
	  workspace[2] = (JCOEF) pred;
	}
	/* OK, do the IDCT */
	(*inverse_DCT) (cinfo, compptr, (JCOEFPTR) workspace,
			output_ptr, output_col);
	/* Advance for next column */
	DC1 = DC2; DC2 = DC3;
	DC4 = DC5; DC5 = DC6;
	DC7 = DC8; DC8 = DC9;
	buffer_ptr++, prev_block_row++, next_block_row++;
	output_col += compptr->DCT_scaled_size;
      }
      output_ptr += compptr->DCT_scaled_size;
    }
  }

  if (++(cinfo->output_iMCU_row) < cinfo->total_iMCU_rows)
    return JPEG_ROW_COMPLETED;
  return JPEG_SCAN_COMPLETED;
}

#endif /* BLOCK_SMOOTHING_SUPPORTED */


/*
 * Initialize coefficient buffer controller.
 */

GLOBAL(void)
jinit_d_coef_controller (j_decompress_ptr cinfo, boolean need_full_buffer)
{
  my_coef_ptr coef;

  coef = (my_coef_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_coef_controller));
  cinfo->coef = (struct jpeg_d_coef_controller *) coef;
  coef->pub.start_input_pass = Cstart_input_pass;
  coef->pub.start_output_pass = start_output_pass;
#ifdef BLOCK_SMOOTHING_SUPPORTED
  coef->coef_bits_latch = NULL;
#endif

  /* Create the coefficient buffer. */
  if (need_full_buffer) {
    /* Allocate a full-image virtual array for each component, */
    /* padded to a multiple of samp_factor DCT blocks in each direction. */
    /* Note we ask for a pre-zeroed array. */
    int ci, access_rows;
    jpeg_component_info *compptr;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
	 ci++, compptr++) {
      access_rows = compptr->v_samp_factor;
#ifdef BLOCK_SMOOTHING_SUPPORTED
      /* If block smoothing could be used, need a bigger window */
      if (cinfo->progressive_mode)
	access_rows *= 3;
#endif
      coef->whole_image[ci] = (*cinfo->mem->request_virt_barray)
	((j_common_ptr) cinfo, JPOOL_IMAGE, TRUE,
	 (JDIMENSION) jround_up((long) compptr->width_in_blocks,
				(long) compptr->h_samp_factor),
	 (JDIMENSION) jround_up((long) compptr->height_in_blocks,
				(long) compptr->v_samp_factor),
	 (JDIMENSION) access_rows);
    }
    coef->pub.consume_data = consume_data;
    coef->pub.decompress_data = decompress_data;
    coef->pub.coef_arrays = coef->whole_image; /* link to virtual arrays */
  } else {
    /* We only need a single-MCU buffer. */
    JBLOCKROW buffer;
    int i;

    buffer = (JBLOCKROW)
      (*cinfo->mem->alloc_large) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  D_MAX_BLOCKS_IN_MCU * SIZEOF(JBLOCK));
    for (i = 0; i < D_MAX_BLOCKS_IN_MCU; i++) {
      coef->MCU_buffer[i] = buffer + i;
    }
    coef->pub.consume_data = dummy_consume_data;
    coef->pub.decompress_data = decompress_onepass;
    coef->pub.coef_arrays = NULL; /* flag for no virtual arrays */
  }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdcolor.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains output colorspace conversion routines.
 */

/* Private subobject */

typedef struct {
  struct jpeg_color_deconverter pub; /* public fields */

  /* Private state for YCC->RGB conversion */
  int * Cr_r_tab;		/* => table for Cr to R conversion */
  int * Cb_b_tab;		/* => table for Cb to B conversion */
  INT32 * Cr_g_tab;		/* => table for Cr to G conversion */
  INT32 * Cb_g_tab;		/* => table for Cb to G conversion */
} my_color_deconverter;

typedef my_color_deconverter * my_cconvert_ptr;


/**************** YCbCr -> RGB conversion: most common case **************/

/*
 * YCbCr is defined per CCIR 601-1, except that Cb and Cr are
 * normalized to the range 0..MAXJSAMPLE rather than -0.5 .. 0.5.
 * The conversion equations to be implemented are therefore
 *	R = Y                + 1.40200 * Cr
 *	G = Y - 0.34414 * Cb - 0.71414 * Cr
 *	B = Y + 1.77200 * Cb
 * where Cb and Cr represent the incoming values less CENTERJSAMPLE.
 * (These numbers are derived from TIFF 6.0 section 21, dated 3-June-92.)
 *
 * To avoid floating-point arithmetic, we represent the fractional constants
 * as integers scaled up by 2^16 (about 4 digits precision); we have to divide
 * the products by 2^16, with appropriate rounding, to get the correct answer.
 * Notice that Y, being an integral input, does not contribute any fraction
 * so it need not participate in the rounding.
 *
 * For even more speed, we avoid doing any multiplications in the inner loop
 * by precalculating the constants times Cb and Cr for all possible values.
 * For 8-bit JSAMPLEs this is very reasonable (only 256 entries per table);
 * for 12-bit samples it is still acceptable.  It's not very reasonable for
 * 16-bit samples, but if you want lossless storage you shouldn't be changing
 * colorspace anyway.
 * The Cr=>R and Cb=>B values can be rounded to integers in advance; the
 * values for the G calculation are left scaled up, since we must add them
 * together before rounding.
 */

#define SCALEBITS	16	/* speediest right-shift on some machines */
#define ONE_HALF	((INT32) 1 << (SCALEBITS-1))
#define MERGEFIX(x)	((INT32) ((x) * (1L<<SCALEBITS) + 0.5))

/*
 * Initialize tables for YCC->RGB colorspace conversion.
 */

LOCAL(void)
Cbuild_ycc_rgb_table (j_decompress_ptr cinfo)
{
  my_cconvert_ptr cconvert = (my_cconvert_ptr) cinfo->cconvert;
  int i;
  INT32 x;
  SHIFT_TEMPS

  cconvert->Cr_r_tab = (int *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(int));
  cconvert->Cb_b_tab = (int *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(int));
  cconvert->Cr_g_tab = (INT32 *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(INT32));
  cconvert->Cb_g_tab = (INT32 *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(INT32));

  for (i = 0, x = -CENTERJSAMPLE; i <= MAXJSAMPLE; i++, x++) {
    /* i is the actual input pixel value, in the range 0..MAXJSAMPLE */
    /* The Cb or Cr value we are thinking of is x = i - CENTERJSAMPLE */
    /* Cr=>R value is nearest int to 1.40200 * x */
    cconvert->Cr_r_tab[i] = (int)
		    RIGHT_SHIFT(MERGEFIX(1.40200) * x + ONE_HALF, SCALEBITS);
    /* Cb=>B value is nearest int to 1.77200 * x */
    cconvert->Cb_b_tab[i] = (int)
		    RIGHT_SHIFT(MERGEFIX(1.77200) * x + ONE_HALF, SCALEBITS);
    /* Cr=>G value is scaled-up -0.71414 * x */
    cconvert->Cr_g_tab[i] = (- MERGEFIX(0.71414)) * x;
    /* Cb=>G value is scaled-up -0.34414 * x */
    /* We also add in ONE_HALF so that need not do it in inner loop */
    cconvert->Cb_g_tab[i] = (- MERGEFIX(0.34414)) * x + ONE_HALF;
  }
}


/*
 * Convert some rows of samples to the output colorspace.
 *
 * Note that we change from noninterleaved, one-plane-per-component format
 * to interleaved-pixel format.  The output buffer is therefore three times
 * as wide as the input buffer.
 * A starting row offset is provided only for the input buffer.  The caller
 * can easily adjust the passed output_buf value to accommodate any row
 * offset required on that side.
 */

METHODDEF(void)
ycc_rgb_convert (j_decompress_ptr cinfo,
		 JSAMPIMAGE input_buf, JDIMENSION input_row,
		 JSAMPARRAY output_buf, int num_rows)
{
  my_cconvert_ptr cconvert = (my_cconvert_ptr) cinfo->cconvert;
  register int y, cb, cr;
  register JSAMPROW outptr;
  register JSAMPROW inptr0, inptr1, inptr2;
  register JDIMENSION col;
  JDIMENSION num_cols = cinfo->output_width;
  /* copy these pointers into registers if possible */
  register JSAMPLE * range_limit = cinfo->sample_range_limit;
  register int * Crrtab = cconvert->Cr_r_tab;
  register int * Cbbtab = cconvert->Cb_b_tab;
  register INT32 * Crgtab = cconvert->Cr_g_tab;
  register INT32 * Cbgtab = cconvert->Cb_g_tab;
  SHIFT_TEMPS

  while (--num_rows >= 0) {
    inptr0 = input_buf[0][input_row];
    inptr1 = input_buf[1][input_row];
    inptr2 = input_buf[2][input_row];
    input_row++;
    outptr = *output_buf++;
    for (col = 0; col < num_cols; col++) {
      y  = GETJSAMPLE(inptr0[col]);
      cb = GETJSAMPLE(inptr1[col]);
      cr = GETJSAMPLE(inptr2[col]);
      /* Range-limiting is essential due to noise introduced by DCT losses. */
      outptr[RGB_RED] =   range_limit[y + Crrtab[cr]];
      outptr[RGB_GREEN] = range_limit[y +
			      ((int) RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr],
						 SCALEBITS))];
      outptr[RGB_BLUE] =  range_limit[y + Cbbtab[cb]];
      outptr += RGB_PIXELSIZE;
    }
  }
}


/**************** Cases other than YCbCr -> RGB **************/


/*
 * Color conversion for no colorspace change: just copy the data,
 * converting from separate-planes to interleaved representation.
 */

METHODDEF(void)
null_convert (j_decompress_ptr cinfo,
	      JSAMPIMAGE input_buf, JDIMENSION input_row,
	      JSAMPARRAY output_buf, int num_rows)
{
  register JSAMPROW inptr, outptr;
  register JDIMENSION count;
  register int num_components = cinfo->num_components;
  JDIMENSION num_cols = cinfo->output_width;
  int ci;

  while (--num_rows >= 0) {
    for (ci = 0; ci < num_components; ci++) {
      inptr = input_buf[ci][input_row];
      outptr = output_buf[0] + ci;
      for (count = num_cols; count > 0; count--) {
	*outptr = *inptr++;	/* needn't bother with GETJSAMPLE() here */
	outptr += num_components;
      }
    }
    input_row++;
    output_buf++;
  }
}


/*
 * Color conversion for grayscale: just copy the data.
 * This also works for YCbCr -> grayscale conversion, in which
 * we just copy the Y (luminance) component and ignore chrominance.
 */

METHODDEF(void)
grayscale_convert (j_decompress_ptr cinfo,
		   JSAMPIMAGE input_buf, JDIMENSION input_row,
		   JSAMPARRAY output_buf, int num_rows)
{
  jcopy_sample_rows(input_buf[0], (int) input_row, output_buf, 0,
		    num_rows, cinfo->output_width);
}


/*
 * Convert grayscale to RGB: just duplicate the graylevel three times.
 * This is provided to support applications that don't want to cope
 * with grayscale as a separate case.
 */

METHODDEF(void)
gray_rgb_convert (j_decompress_ptr cinfo,
		  JSAMPIMAGE input_buf, JDIMENSION input_row,
		  JSAMPARRAY output_buf, int num_rows)
{
  register JSAMPROW inptr, outptr;
  register JDIMENSION col;
  JDIMENSION num_cols = cinfo->output_width;

  while (--num_rows >= 0) {
    inptr = input_buf[0][input_row++];
    outptr = *output_buf++;
    for (col = 0; col < num_cols; col++) {
      /* We can dispense with GETJSAMPLE() here */
      outptr[RGB_RED] = outptr[RGB_GREEN] = outptr[RGB_BLUE] = inptr[col];
      outptr += RGB_PIXELSIZE;
    }
  }
}


/*
 * Empty method for start_pass.
 */

int start_pass_dcolor (j_decompress_ptr cinfo)
{
  /* no work needed */
  return 0;
}


/*
 * Module initialization routine for output colorspace conversion.
 */

int jinit_color_deconverter (j_decompress_ptr cinfo) {

  my_cconvert_ptr cconvert;

  cconvert = (my_cconvert_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_color_deconverter));
  cinfo->cconvert = (struct jpeg_color_deconverter *) cconvert;
  cconvert->pub.start_pass = start_pass_dcolor;

  /* Make sure num_components agrees with jpeg_color_space */
  switch (cinfo->jpeg_color_space) {
  case JCS_GRAYSCALE:
    if (cinfo->num_components != 1) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    break;

  case JCS_RGB:
  case JCS_YCbCr:
    if (cinfo->num_components != 3) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    break;

  case JCS_CMYK:
  case JCS_YCCK:
    if (cinfo->num_components != 4) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    break;

  default:			/* JCS_UNKNOWN can be anything */
    if (cinfo->num_components < 1) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    break;
  }

  /* Set out_color_components and conversion method based on requested space.
   * Also clear the component_needed flags for any unused components,
   * so that earlier pipeline stages can avoid useless computation.
   */

    cinfo->out_color_components = RGB_PIXELSIZE;
    if (cinfo->jpeg_color_space == JCS_YCbCr) {
      cconvert->pub.color_convert = ycc_rgb_convert;
      Cbuild_ycc_rgb_table(cinfo);
    } else if (cinfo->jpeg_color_space == JCS_GRAYSCALE) {
      cconvert->pub.color_convert = gray_rgb_convert;
    } else if (cinfo->jpeg_color_space == JCS_RGB && RGB_PIXELSIZE == 3) {
      cconvert->pub.color_convert = null_convert;
    } else {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

    cinfo->output_components = cinfo->out_color_components;
	return 0;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jddctmgr.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the inverse-DCT management logic.
 * This code selects a particular IDCT implementation to be used,
 * and it performs related housekeeping chores.  No code in this file
 * is executed per IDCT step, only during output pass setup.
 *
 * Note that the IDCT routines are responsible for performing coefficient
 * dequantization as well as the IDCT proper.  This module sets up the
 * dequantization multiplier table needed by the IDCT routine.
 */

/*
 * The decompressor input side (jdinput.c) saves away the appropriate
 * quantization table for each component at the start of the first scan
 * involving that component.  (This is necessary in order to correctly
 * decode files that reuse Q-table slots.)
 * When we are ready to make an output pass, the saved Q-table is converted
 * to a multiplier table that will actually be used by the IDCT routine.
 * The multiplier table contents are IDCT-method-dependent.  To support
 * application changes in IDCT method between scans, we can remake the
 * multiplier tables if necessary.
 * In buffered-image mode, the first output pass may occur before any data
 * has been seen for some components, and thus before their Q-tables have
 * been saved away.  To handle this case, multiplier tables are preset
 * to zeroes; the result of the IDCT will be a neutral gray level.
 */


/* Private subobject for this module */

typedef struct {
  struct jpeg_inverse_dct pub;	/* public fields */

  /* This array contains the IDCT method code that each multiplier table
   * is currently set up for, or -1 if it's not yet set up.
   * The actual multiplier tables are pointed to by dct_table in the
   * per-component comp_info structures.
   */
  int cur_method[MAX_COMPONENTS];
} my_idct_controller;

typedef my_idct_controller * my_idct_ptr;


/* Allocated multiplier tables: big enough for any supported variant */

typedef union {
  ISLOW_MULT_TYPE islow_array[DCTSIZE2];
#ifdef DCT_FLOAT_SUPPORTED
  FLOAT_MULT_TYPE float_array[DCTSIZE2];
#endif
} multiplier_table;


/* The current scaled-IDCT routines require ISLOW-style multiplier tables,
 * so be sure to compile that code if either ISLOW or SCALING is requested.
 */
#ifdef DCT_ISLOW_SUPPORTED
#define PROVIDE_ISLOW_TABLES
#endif


/*
 * Prepare for an output pass.
 * Here we select the proper IDCT routine for each component and build
 * a matching multiplier table.
 */

int start_pass (j_decompress_ptr cinfo) {

  my_idct_ptr idct = (my_idct_ptr) cinfo->idct;
  int ci, i;
  jpeg_component_info *compptr;
  int method = 0;
  inverse_DCT_method_ptr method_ptr = NULL;
  JQUANT_TBL * qtbl;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Select the proper IDCT routine for this component's scaling */
    switch (compptr->DCT_scaled_size) {
    case DCTSIZE:
      switch (cinfo->dct_method) {
#ifdef DCT_ISLOW_SUPPORTED
      case JDCT_ISLOW:
	method_ptr = jpeg_idct_islow;
	method = JDCT_ISLOW;
	break;
#endif
#ifdef DCT_IFAST_SUPPORTED
      case JDCT_IFAST:
	method_ptr = jpeg_idct_ifast;
	method = JDCT_IFAST;
	break;
#endif
#ifdef DCT_FLOAT_SUPPORTED
      case JDCT_FLOAT:
	method_ptr = jpeg_idct_float;
	method = JDCT_FLOAT;
	break;
#endif
      default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
      }
      break;
    default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
    }
    idct->pub.inverse_DCT[ci] = method_ptr;
    /* Create multiplier table from quant table.
     * However, we can skip this if the component is uninteresting
     * or if we already built the table.  Also, if no quant table
     * has yet been saved for the component, we leave the
     * multiplier table all-zero; we'll be reading zeroes from the
     * coefficient controller's buffer anyway.
     */
    if (! compptr->component_needed || idct->cur_method[ci] == method)
      continue;
    qtbl = compptr->quant_table;
    if (qtbl == NULL)		/* happens if no data yet for component */
      continue;
    idct->cur_method[ci] = method;
    switch (method) {
#ifdef PROVIDE_ISLOW_TABLES
    case JDCT_ISLOW:
      {
	/* For LL&M IDCT method, multipliers are equal to raw quantization
	 * coefficients, but are stored as ints to ensure access efficiency.
	 */
	ISLOW_MULT_TYPE * ismtbl = (ISLOW_MULT_TYPE *) compptr->dct_table;
	for (i = 0; i < DCTSIZE2; i++) {
	  ismtbl[i] = (ISLOW_MULT_TYPE) qtbl->quantval[i];
	}
      }
      break;
#endif
#ifdef DCT_IFAST_SUPPORTED
    case JDCT_IFAST:
      {
	/* For AA&N IDCT method, multipliers are equal to quantization
	 * coefficients scaled by scalefactor[row]*scalefactor[col], where
	 *   scalefactor[0] = 1
	 *   scalefactor[k] = cos(k*PI/16) * sqrt(2)    for k=1..7
	 * For integer operation, the multiplier table is to be scaled by
	 * IFAST_SCALE_BITS.
	 */
	IFAST_MULT_TYPE * ifmtbl = (IFAST_MULT_TYPE *) compptr->dct_table;
#define CONST_BITS 14
	static const INT16 aanscales[DCTSIZE2] = {
	  /* precomputed values scaled up by 14 bits */
	  16384, 22725, 21407, 19266, 16384, 12873,  8867,  4520,
	  22725, 31521, 29692, 26722, 22725, 17855, 12299,  6270,
	  21407, 29692, 27969, 25172, 21407, 16819, 11585,  5906,
	  19266, 26722, 25172, 22654, 19266, 15137, 10426,  5315,
	  16384, 22725, 21407, 19266, 16384, 12873,  8867,  4520,
	  12873, 17855, 16819, 15137, 12873, 10114,  6967,  3552,
	   8867, 12299, 11585, 10426,  8867,  6967,  4799,  2446,
	   4520,  6270,  5906,  5315,  4520,  3552,  2446,  1247
	};
	SHIFT_TEMPS

	for (i = 0; i < DCTSIZE2; i++) {
	  ifmtbl[i] = (IFAST_MULT_TYPE)
	    DESCALE(MULTIPLY16V16((INT32) qtbl->quantval[i],
				  (INT32) aanscales[i]),
		    CONST_BITS-IFAST_SCALE_BITS);
	}
      }
      break;
#endif
#ifdef DCT_FLOAT_SUPPORTED
    case JDCT_FLOAT:
      {
	/* For float AA&N IDCT method, multipliers are equal to quantization
	 * coefficients scaled by scalefactor[row]*scalefactor[col], where
	 *   scalefactor[0] = 1
	 *   scalefactor[k] = cos(k*PI/16) * sqrt(2)    for k=1..7
	 */
	FLOAT_MULT_TYPE * fmtbl = (FLOAT_MULT_TYPE *) compptr->dct_table;
	int row, col;
	static const double aanscalefactor[DCTSIZE] = {
	  1.0, 1.387039845, 1.306562965, 1.175875602,
	  1.0, 0.785694958, 0.541196100, 0.275899379
	};

	i = 0;
	for (row = 0; row < DCTSIZE; row++) {
	  for (col = 0; col < DCTSIZE; col++) {
	    fmtbl[i] = (FLOAT_MULT_TYPE)
	      ((double) qtbl->quantval[i] *
	       aanscalefactor[row] * aanscalefactor[col]);
	    i++;
	  }
	}
      }
      break;
#endif
    default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
    }
  }
	return 0;
}


/*
 * Initialize IDCT manager.
 */

GLOBAL(void)
jinit_inverse_dct (j_decompress_ptr cinfo)
{
  my_idct_ptr idct;
  int ci;
  jpeg_component_info *compptr;

  idct = (my_idct_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_idct_controller));
  cinfo->idct = (struct jpeg_inverse_dct *) idct;
  idct->pub.start_pass = start_pass;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Allocate and pre-zero a multiplier table for each component */
    compptr->dct_table =
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  SIZEOF(multiplier_table));
    MEMZERO(compptr->dct_table, SIZEOF(multiplier_table));
    /* Mark multiplier table not yet set up for any method */
    idct->cur_method[ci] = -1;
  }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdhuff.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains Huffman entropy decoding routines.
 *
 * Much of the complexity here has to do with supporting input suspension.
 * If the data source module demands suspension, we want to be able to back
 * up to the start of the current MCU.  To do this, we copy state variables
 * into local working storage, and update them back to the permanent
 * storage only upon successful completion of an MCU.
 */

/*
 * Expanded entropy decoder object for Huffman decoding.
 *
 * The hsavable_state subrecord contains fields that change within an MCU,
 * but must not be updated permanently until we complete the MCU.
 */

typedef struct {
  int last_dc_val[MAX_COMPS_IN_SCAN]; /* last DC coef for each component */
} hsavable_state;

/* This macro is to work around compilers with missing or broken
 * structure assignment.  You'll need to fix this code if you have
 * such a compiler and you change MAX_COMPS_IN_SCAN.
 */

#ifndef NO_STRUCT_ASSIGN
#define ASSIGN_STATE(dest,src)  ((dest) = (src))
#else
#if MAX_COMPS_IN_SCAN == 4
#define ASSIGN_STATE(dest,src)  \
	((dest).last_dc_val[0] = (src).last_dc_val[0], \
	 (dest).last_dc_val[1] = (src).last_dc_val[1], \
	 (dest).last_dc_val[2] = (src).last_dc_val[2], \
	 (dest).last_dc_val[3] = (src).last_dc_val[3])
#endif
#endif


typedef struct {
  struct jpeg_entropy_decoder pub; /* public fields */

  /* These fields are loaded into local variables at start of each MCU.
   * In case of suspension, we exit WITHOUT updating them.
   */
  bitread_perm_state bitstate;	/* Bit buffer at start of MCU */
  hsavable_state saved;		/* Other state at start of MCU */

  /* These fields are NOT loaded into local working state. */
  unsigned int restarts_to_go;	/* MCUs left in this restart interval */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  d_derived_tbl * dc_derived_tbls[NUM_HUFF_TBLS];
  d_derived_tbl * ac_derived_tbls[NUM_HUFF_TBLS];

  /* Precalculated info set up by start_pass for use in decode_mcu: */

  /* Pointers to derived tables to be used for each block within an MCU */
  d_derived_tbl * dc_cur_tbls[D_MAX_BLOCKS_IN_MCU];
  d_derived_tbl * ac_cur_tbls[D_MAX_BLOCKS_IN_MCU];
  /* Whether we care about the DC and AC coefficient values for each block */
  boolean dc_needed[D_MAX_BLOCKS_IN_MCU];
  boolean ac_needed[D_MAX_BLOCKS_IN_MCU];
} huff_entropy_decoder;

typedef huff_entropy_decoder * huff_entropy_ptr;


/*
 * Initialize for a Huffman-compressed scan.
 */

int start_pass_huff_decoder (j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr) cinfo->entropy;
  int ci, blkn, dctbl, actbl;
  jpeg_component_info * compptr;

  /* Check that the scan parameters Ss, Se, Ah/Al are OK for sequential JPEG.
   * This ought to be an error condition, but we make it a warning because
   * there are some baseline files out there with all zeroes in these bytes.
   */
  if (cinfo->Ss != 0 || cinfo->Se != DCTSIZE2-1 ||
      cinfo->Ah != 0 || cinfo->Al != 0) {
//    WARNMS(cinfo, JWRN_NOT_SEQUENTIAL);
	}

  for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
    compptr = cinfo->cur_comp_info[ci];
    dctbl = compptr->dc_tbl_no;
    actbl = compptr->ac_tbl_no;
    /* Compute derived values for Huffman tables */
    /* We may do this more than once for a table, but it's not expensive */
    jpeg_make_d_derived_tbl(cinfo, TRUE, dctbl,
			    & entropy->dc_derived_tbls[dctbl]);
    jpeg_make_d_derived_tbl(cinfo, FALSE, actbl,
			    & entropy->ac_derived_tbls[actbl]);
    /* Initialize DC predictions to 0 */
    entropy->saved.last_dc_val[ci] = 0;
  }

  /* Precalculate decoding info for each block in an MCU of this scan */
  for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
    ci = cinfo->MCU_membership[blkn];
    compptr = cinfo->cur_comp_info[ci];
    /* Precalculate which table to use for each block */
    entropy->dc_cur_tbls[blkn] = entropy->dc_derived_tbls[compptr->dc_tbl_no];
    entropy->ac_cur_tbls[blkn] = entropy->ac_derived_tbls[compptr->ac_tbl_no];
    /* Decide whether we really care about the coefficient values */
    if (compptr->component_needed) {
      entropy->dc_needed[blkn] = TRUE;
      /* we don't need the ACs if producing a 1/8th-size image */
      entropy->ac_needed[blkn] = (compptr->DCT_scaled_size > 1);
    } else {
      entropy->dc_needed[blkn] = entropy->ac_needed[blkn] = FALSE;
    }
  }

  /* Initialize bitread state variables */
  entropy->bitstate.bits_left = 0;
  entropy->bitstate.get_buffer = 0; /* unnecessary, but keeps Purify quiet */
  entropy->pub.insufficient_data = FALSE;

  /* Initialize restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;
  return 0;
}


/*
 * Compute the derived values for a Huffman table.
 * This routine also performs some validation checks on the table.
 *
 * Note this is also used by jdphuff.c.
 */

int jpeg_make_d_derived_tbl (j_decompress_ptr cinfo, boolean isDC, int tblno, d_derived_tbl ** pdtbl) {

  JHUFF_TBL *htbl;
  d_derived_tbl *dtbl;
  int p, i, l, si, numsymbols;
  int lookbits, ctr;
  char huffsize[257];
  unsigned int huffcode[257];
  unsigned int code;

  /* Note that huffsize[] and huffcode[] are filled in code-length order,
   * paralleling the order of the symbols themselves in htbl->huffval[].
   */

  /* Find the input Huffman table */
  if (tblno < 0 || tblno >= NUM_HUFF_TBLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
  htbl =
    isDC ? cinfo->dc_huff_tbl_ptrs[tblno] : cinfo->ac_huff_tbl_ptrs[tblno];
	if (htbl == NULL) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* Allocate a workspace if we haven't already done so. */
  if (*pdtbl == NULL)
    *pdtbl = (d_derived_tbl *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  SIZEOF(d_derived_tbl));
  dtbl = *pdtbl;
  dtbl->pub = htbl;		/* fill in back link */
  
  /* Figure C.1: make table of Huffman code length for each symbol */

  p = 0;
  for (l = 1; l <= 16; l++) {
    i = (int) htbl->bits[l];
    if (i < 0 || p + i > 256) {	/* protect against table overrun */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    while (i--)
      huffsize[p++] = (char) l;
  }
  huffsize[p] = 0;
  numsymbols = p;
  
  /* Figure C.2: generate the codes themselves */
  /* We also validate that the counts represent a legal Huffman code tree. */
  
  code = 0;
  si = huffsize[0];
  p = 0;
  while (huffsize[p]) {
    while (((int) huffsize[p]) == si) {
      huffcode[p++] = code;
      code++;
    }
    /* code is now 1 more than the last code used for codelength si; but
     * it must still fit in si bits, since no code is allowed to be all ones.
     */
    if (((INT32) code) >= (((INT32) 1) << si)) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    code <<= 1;
    si++;
  }

  /* Figure F.15: generate decoding tables for bit-sequential decoding */

  p = 0;
  for (l = 1; l <= 16; l++) {
    if (htbl->bits[l]) {
      /* valoffset[l] = huffval[] index of 1st symbol of code length l,
       * minus the minimum code of length l
       */
      dtbl->valoffset[l] = (INT32) p - (INT32) huffcode[p];
      p += htbl->bits[l];
      dtbl->maxcode[l] = huffcode[p-1]; /* maximum code of length l */
    } else {
      dtbl->maxcode[l] = -1;	/* -1 if no codes of this length */
    }
  }
  dtbl->maxcode[17] = 0xFFFFFL; /* ensures jpeg_huff_decode terminates */

  /* Compute lookahead tables to speed up decoding.
   * First we set all the table entries to 0, indicating "too long";
   * then we iterate through the Huffman codes that are short enough and
   * fill in all the entries that correspond to bit sequences starting
   * with that code.
   */

  MEMZERO(dtbl->look_nbits, SIZEOF(dtbl->look_nbits));

  p = 0;
  for (l = 1; l <= HUFF_LOOKAHEAD; l++) {
    for (i = 1; i <= (int) htbl->bits[l]; i++, p++) {
      /* l = current code's length, p = its index in huffcode[] & huffval[]. */
      /* Generate left-justified code followed by all possible bit sequences */
      lookbits = huffcode[p] << (HUFF_LOOKAHEAD-l);
      for (ctr = 1 << (HUFF_LOOKAHEAD-l); ctr > 0; ctr--) {
	dtbl->look_nbits[lookbits] = l;
	dtbl->look_sym[lookbits] = htbl->huffval[p];
	lookbits++;
      }
    }
  }

  /* Validate symbols as being reasonable.
   * For AC tables, we make no check, but accept all byte values 0..255.
   * For DC tables, we require the symbols to be in range 0..15.
   * (Tighter bounds could be applied depending on the data depth and mode,
   * but this is sufficient to ensure safe decoding.)
   */
	if (isDC) {
		for (i = 0; i < numsymbols; i++) {
			int sym = htbl->huffval[i];

			if (sym < 0 || sym > 15) {
				jpeg_destroy((j_common_ptr)&cinfo);
				return -1;
			}
		}
	}
	return 0;
}


/*
 * Out-of-line code for bit fetching (shared with jdphuff.c).
 * See jdhuff.h for info about usage.
 * Note: current values of get_buffer and bits_left are passed as parameters,
 * but are returned in the corresponding fields of the state struct.
 *
 * On most machines MIN_GET_BITS should be 25 to allow the full 32-bit width
 * of get_buffer to be used.  (On machines with wider words, an even larger
 * buffer could be used.)  However, on some machines 32-bit shifts are
 * quite slow and take time proportional to the number of places shifted.
 * (This is true with most PC compilers, for instance.)  In this case it may
 * be a win to set MIN_GET_BITS to the minimum value of 15.  This reduces the
 * average shift distance at the cost of more calls to jpeg_fill_bit_buffer.
 */

#ifdef SLOW_SHIFT_32
#define MIN_GET_BITS  15	/* minimum allowable value */
#else
#define MIN_GET_BITS  (BIT_BUF_SIZE-7)
#endif


int jpeg_fill_bit_buffer (bitread_working_state * state, register bit_buf_type get_buffer, register int bits_left, int nbits) {
/* Load up the bit buffer to a depth of at least nbits */
	int retval;

  /* Copy heavily used state fields into locals (hopefully registers) */
  register const JOCTET * next_input_byte = state->next_input_byte;
  register size_t bytes_in_buffer = state->bytes_in_buffer;
  j_decompress_ptr cinfo = state->cinfo;

  /* Attempt to load at least MIN_GET_BITS bits into get_buffer. */
  /* (It is assumed that no request will be for more than that many bits.) */
  /* We fail to do so only if we hit a marker or are forced to suspend. */

  if (cinfo->unread_marker == 0) {	/* cannot advance past a marker */
    while (bits_left < MIN_GET_BITS) {
      register int c;

      /* Attempt to read a byte */
      if (bytes_in_buffer == 0) {
		if( (retval=(*cinfo->src->fill_input_buffer) (cinfo)) <= 0 ) return retval;
		next_input_byte = cinfo->src->next_input_byte;
		bytes_in_buffer = cinfo->src->bytes_in_buffer;
      }
      bytes_in_buffer--;
      c = GETJOCTET(*next_input_byte++);

      /* If it's 0xFF, check and discard stuffed zero byte */
      if (c == 0xFF) {
	/* Loop here to discard any padding FF's on terminating marker,
	 * so that we can save a valid unread_marker value.  NOTE: we will
	 * accept multiple FF's followed by a 0 as meaning a single FF data
	 * byte.  This data pattern is not valid according to the standard.
	 */
	do {
	  if (bytes_in_buffer == 0) {
	    if ( (retval=(*cinfo->src->fill_input_buffer) (cinfo)) <= 0 ) return retval;
	    next_input_byte = cinfo->src->next_input_byte;
	    bytes_in_buffer = cinfo->src->bytes_in_buffer;
	  }
	  bytes_in_buffer--;
	  c = GETJOCTET(*next_input_byte++);
	} while (c == 0xFF);

	if (c == 0) {
	  /* Found FF/00, which represents an FF data byte */
	  c = 0xFF;
	} else {
	  /* Oops, it's actually a marker indicating end of compressed data.
	   * Save the marker code for later use.
	   * Fine point: it might appear that we should save the marker into
	   * bitread working state, not straight into permanent state.  But
	   * once we have hit a marker, we cannot need to suspend within the
	   * current MCU, because we will read no more bytes from the data
	   * source.  So it is OK to update permanent state right away.
	   */
	  cinfo->unread_marker = c;
	  /* See if we need to insert some fake zero bits. */
	  goto no_more_bytes;
	}
      }

      /* OK, load c into get_buffer */
      get_buffer = (get_buffer << 8) | c;
      bits_left += 8;
    } /* end while */
  } else {
  no_more_bytes:
    /* We get here if we've read the marker that terminates the compressed
     * data segment.  There should be enough bits in the buffer register
     * to satisfy the request; if so, no problem.
     */
    if (nbits > bits_left) {
      /* Uh-oh.  Report corrupted data to user and stuff zeroes into
       * the data stream, so that we can produce some kind of image.
       * We use a nonvolatile flag to ensure that only one warning message
       * appears per data segment.
       */
      if (! cinfo->entropy->insufficient_data) {
//	WARNMS(cinfo, JWRN_HIT_MARKER);
	cinfo->entropy->insufficient_data = TRUE;
      }
      /* Fill the buffer with zero bits */
      get_buffer <<= MIN_GET_BITS - bits_left;
      bits_left = MIN_GET_BITS;
    }
  }

  /* Unload the local registers */
  state->next_input_byte = next_input_byte;
  state->bytes_in_buffer = bytes_in_buffer;
  state->get_buffer = get_buffer;
  state->bits_left = bits_left;

  return TRUE;
}


/*
 * Out-of-line code for Huffman code decoding.
 * See jdhuff.h for info about usage.
 */

GLOBAL(int)
jpeg_huff_decode (bitread_working_state * state,
		  register bit_buf_type get_buffer, register int bits_left,
		  d_derived_tbl * htbl, int min_bits)
{
  register int l = min_bits;
  register INT32 code;

  /* HUFF_DECODE has determined that the code is at least min_bits */
  /* bits long, so fetch that many bits in one swoop. */

  CHECK_BIT_BUFFER(*state, l, return -1);
  code = GET_BITS(l);

  /* Collect the rest of the Huffman code one bit at a time. */
  /* This is per Figure F.16 in the JPEG spec. */

  while (code > htbl->maxcode[l]) {
    code <<= 1;
    CHECK_BIT_BUFFER(*state, 1, return -1);
    code |= GET_BITS(1);
    l++;
  }

  /* Unload the local registers */
  state->get_buffer = get_buffer;
  state->bits_left = bits_left;

  /* With garbage input we may reach the sentinel value l = 17. */

  if (l > 16) {
//    WARNMS(state->cinfo, JWRN_HUFF_BAD_CODE);
    return 0;			/* fake a zero as the safest result */
  }

  return htbl->pub->huffval[ (int) (code + htbl->valoffset[l]) ];
}


/*
 * Figure F.12: extend sign bit.
 * On some machines, a shift and add will be faster than a table lookup.
 */

#ifdef AVOID_TABLES

#define HUFF_EXTEND(x,s)  ((x) < (1<<((s)-1)) ? (x) + (((-1)<<(s)) + 1) : (x))

#else

#define HUFF_EXTEND(x,s)  ((x) < extend_test[s] ? (x) + extend_offset[s] : (x))

static const int extend_test[16] =   /* entry n is 2**(n-1) */
  { 0, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000 };

static const int extend_offset[16] = /* entry n is (-1 << n) + 1 */
  { 0, ((-1)<<1) + 1, ((-1)<<2) + 1, ((-1)<<3) + 1, ((-1)<<4) + 1,
    ((-1)<<5) + 1, ((-1)<<6) + 1, ((-1)<<7) + 1, ((-1)<<8) + 1,
    ((-1)<<9) + 1, ((-1)<<10) + 1, ((-1)<<11) + 1, ((-1)<<12) + 1,
    ((-1)<<13) + 1, ((-1)<<14) + 1, ((-1)<<15) + 1 };

#endif /* AVOID_TABLES */


/*
 * Check for a restart marker & resynchronize decoder.
 * Returns FALSE if must suspend.
 */

LOCAL(boolean)
hprocess_restart (j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr) cinfo->entropy;
  int ci;

  /* Throw away any unused bits remaining in bit buffer; */
  /* include any full bytes in next_marker's count of discarded bytes */
  cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
  entropy->bitstate.bits_left = 0;

  /* Advance past the RSTn marker */
  if (! (*cinfo->marker->read_restart_marker) (cinfo)) return FALSE;

  /* Re-initialize DC predictions to 0 */
  for (ci = 0; ci < cinfo->comps_in_scan; ci++)
    entropy->saved.last_dc_val[ci] = 0;

  /* Reset restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;

  /* Reset out-of-data flag, unless read_restart_marker left us smack up
   * against a marker.  In that case we will end up treating the next data
   * segment as empty, and we can avoid producing bogus output pixels by
   * leaving the flag set.
   */
  if (cinfo->unread_marker == 0)
    entropy->pub.insufficient_data = FALSE;

  return TRUE;
}


/*
 * Decode and return one MCU's worth of Huffman-compressed coefficients.
 * The coefficients are reordered from zigzag order into natural array order,
 * but are not dequantized.
 *
 * The i'th block of the MCU is stored into the block pointed to by
 * MCU_data[i].  WE ASSUME THIS AREA HAS BEEN ZEROED BY THE CALLER.
 * (Wholesale zeroing is usually a little faster than retail...)
 *
 * Returns FALSE if data source requested suspension.  In that case no
 * changes have been made to permanent state.  (Exception: some output
 * coefficients may already have been assigned.  This is harmless for
 * this module, since we'll just re-assign them on the next call.)
 */

int decode_mcu (j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
  huff_entropy_ptr entropy = (huff_entropy_ptr) cinfo->entropy;
  int blkn, retval;
  BITREAD_STATE_VARS;
  hsavable_state state;

  /* Process restart marker if needed; may have to suspend */
  if( cinfo->restart_interval && entropy->restarts_to_go==0 && !hprocess_restart(cinfo) ) return FALSE;

  /* If we've run out of data, just leave the MCU set to zeroes.
   * This way, we return uniform gray for the remainder of the segment.
   */
  if (! entropy->pub.insufficient_data) {

    /* Load up working state */
    BITREAD_LOAD_STATE(cinfo,entropy->bitstate);
    ASSIGN_STATE(state, entropy->saved);

    /* Outer loop handles each block in the MCU */

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
      JBLOCKROW block = MCU_data[blkn];
      d_derived_tbl * dctbl = entropy->dc_cur_tbls[blkn];
      d_derived_tbl * actbl = entropy->ac_cur_tbls[blkn];
      register int s, k, r;

      /* Decode a single block's worth of coefficients */

      /* Section F.2.2.1: decode the DC coefficient difference */
//      HUFF_DECODE(s, br_state, dctbl, return FALSE, label1);






//#define HUFF_DECODE(result,state,htbl,failaction,slowlabel) 
{ register int nb, look; 
  if (bits_left < HUFF_LOOKAHEAD) { 
    if ( (retval=jpeg_fill_bit_buffer(&br_state,get_buffer,bits_left, 0)) <=0 ) {
		if( retval ) jpeg_destroy((j_common_ptr)&cinfo);
		return retval;
	}
    get_buffer = br_state.get_buffer; bits_left = br_state.bits_left; 
    if (bits_left < HUFF_LOOKAHEAD) { 
      nb = 1; goto slowlabel; 
    } 
  } 
  look = PEEK_BITS(HUFF_LOOKAHEAD); 
// ERROR: look=F9 on the following line, dctbl==0!!!
  if ((nb = dctbl->look_nbits[look]) != 0) { 
    DROP_BITS(nb); 
    s = dctbl->look_sym[look]; 
  } else { 
    nb = HUFF_LOOKAHEAD+1; 
slowlabel: 
    if ((s=jpeg_huff_decode(&br_state,get_buffer,bits_left,dctbl,nb)) < 0) 
	{ return FALSE; } 
    get_buffer = br_state.get_buffer; bits_left = br_state.bits_left; 
  } 
}




      if (s) {
	CHECK_BIT_BUFFER(br_state, s, return FALSE);
	r = GET_BITS(s);
	s = HUFF_EXTEND(r, s);
      }

      if (entropy->dc_needed[blkn]) {
	/* Convert DC difference to actual value, update last_dc_val */
	int ci = cinfo->MCU_membership[blkn];
	s += state.last_dc_val[ci];
	state.last_dc_val[ci] = s;
	/* Output the DC coefficient (assumes jpeg_natural_order[0] = 0) */
	(*block)[0] = (JCOEF) s;
      }

      if (entropy->ac_needed[blkn]) {

	/* Section F.2.2.2: decode the AC coefficients */
	/* Since zeroes are skipped, output area must be cleared beforehand */
	for (k = 1; k < DCTSIZE2; k++) {
	  HUFF_DECODE(s, br_state, actbl, return FALSE, label2);
      
	  r = s >> 4;
	  s &= 15;
      
	  if (s) {
	    k += r;
	    CHECK_BIT_BUFFER(br_state, s, return FALSE);
	    r = GET_BITS(s);
	    s = HUFF_EXTEND(r, s);
	    /* Output coefficient in natural (dezigzagged) order.
	     * Note: the extra entries in jpeg_natural_order[] will save us
	     * if k >= DCTSIZE2, which could happen if the data is corrupted.
	     */
	    (*block)[jpeg_natural_order[k]] = (JCOEF) s;
	  } else {
	    if (r != 15)
	      break;
	    k += 15;
	  }
	}

      } else {

	/* Section F.2.2.2: decode the AC coefficients */
	/* In this path we just discard the values */
	for (k = 1; k < DCTSIZE2; k++) {
	  HUFF_DECODE(s, br_state, actbl, return FALSE, label3);
      
	  r = s >> 4;
	  s &= 15;
      
	  if (s) {
	    k += r;
	    CHECK_BIT_BUFFER(br_state, s, return FALSE);
	    DROP_BITS(s);
	  } else {
	    if (r != 15)
	      break;
	    k += 15;
	  }
	}

      }
    }

    /* Completed MCU, so update state */
    BITREAD_SAVE_STATE(cinfo,entropy->bitstate);
    ASSIGN_STATE(entropy->saved, state);
  }

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;
}


/*
 * Module initialization routine for Huffman entropy decoding.
 */

GLOBAL(void)
jinit_huff_decoder (j_decompress_ptr cinfo)
{
  huff_entropy_ptr entropy;
  int i;

  entropy = (huff_entropy_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(huff_entropy_decoder));
  cinfo->entropy = (struct jpeg_entropy_decoder *) entropy;
  entropy->pub.start_pass = start_pass_huff_decoder;
  entropy->pub.decode_mcu = decode_mcu;

  /* Mark tables unallocated */
  for (i = 0; i < NUM_HUFF_TBLS; i++) {
    entropy->dc_derived_tbls[i] = entropy->ac_derived_tbls[i] = NULL;
  }
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdinput.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains input control logic for the JPEG decompressor.
 * These routines are concerned with controlling the decompressor's input
 * processing (marker reading and coefficient decoding).  The actual input
 * reading is done in jdmarker.c, jdhuff.c, and jdphuff.c.
 */

/* Private state */

typedef struct {
  struct jpeg_input_controller pub; /* public fields */

  boolean inheaders;		/* TRUE until first SOS is reached */
} my_input_controller;

typedef my_input_controller * my_inputctl_ptr;


/* Forward declarations */
METHODDEF(int) consume_markers JPP((j_decompress_ptr cinfo));


/*
 * Routines to calculate various quantities related to the size of the image.
 */

int initial_setup (j_decompress_ptr cinfo) {
/* Called once, when first SOS marker is reached */

  int ci;
  jpeg_component_info *compptr;

  /* Make sure image isn't bigger than I can handle */
  if ((long) cinfo->image_height > (long) JPEG_MAX_DIMENSION ||
      (long) cinfo->image_width > (long) JPEG_MAX_DIMENSION) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* For now, precision must match compiled-in value... */
  if (cinfo->data_precision != BITS_IN_JSAMPLE) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* Check that number of components won't exceed internal array sizes */
  if (cinfo->num_components > MAX_COMPONENTS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
	     

  /* Compute maximum sampling factors; check factor validity */
  cinfo->max_h_samp_factor = 1;
  cinfo->max_v_samp_factor = 1;
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    if (compptr->h_samp_factor<=0 || compptr->h_samp_factor>MAX_SAMP_FACTOR ||
	compptr->v_samp_factor<=0 || compptr->v_samp_factor>MAX_SAMP_FACTOR) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    cinfo->max_h_samp_factor = MAX(cinfo->max_h_samp_factor,
				   compptr->h_samp_factor);
    cinfo->max_v_samp_factor = MAX(cinfo->max_v_samp_factor,
				   compptr->v_samp_factor);
  }

  /* We initialize DCT_scaled_size and min_DCT_scaled_size to DCTSIZE.
   * In the full decompressor, this will be overridden by jdmaster.c;
   * but in the transcoder, jdmaster.c is not used, so we must do it here.
   */
  cinfo->min_DCT_scaled_size = DCTSIZE;

  /* Compute dimensions of components */
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    compptr->DCT_scaled_size = DCTSIZE;
    /* Size in DCT blocks */
    compptr->width_in_blocks = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_width * (long) compptr->h_samp_factor,
		    (long) (cinfo->max_h_samp_factor * DCTSIZE));
    compptr->height_in_blocks = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_height * (long) compptr->v_samp_factor,
		    (long) (cinfo->max_v_samp_factor * DCTSIZE));
    /* downsampled_width and downsampled_height will also be overridden by
     * jdmaster.c if we are doing full decompression.  The transcoder library
     * doesn't use these values, but the calling application might.
     */
    /* Size in samples */
    compptr->downsampled_width = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_width * (long) compptr->h_samp_factor,
		    (long) cinfo->max_h_samp_factor);
    compptr->downsampled_height = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_height * (long) compptr->v_samp_factor,
		    (long) cinfo->max_v_samp_factor);
    /* Mark component needed, until color conversion says otherwise */
    compptr->component_needed = TRUE;
    /* Mark no quantization table yet saved for component */
    compptr->quant_table = NULL;
  }

  /* Compute number of fully interleaved MCU rows. */
  cinfo->total_iMCU_rows = (JDIMENSION)
    jdiv_round_up((long) cinfo->image_height,
		  (long) (cinfo->max_v_samp_factor*DCTSIZE));

  /* Decide whether file contains multiple scans */
  if (cinfo->comps_in_scan < cinfo->num_components || cinfo->progressive_mode)
    cinfo->inputctl->has_multiple_scans = TRUE;
  else
    cinfo->inputctl->has_multiple_scans = FALSE;
	return 0;
}


int per_scan_setup (j_decompress_ptr cinfo) {
/* Do computations that are needed before processing a JPEG scan */
/* cinfo->comps_in_scan and cinfo->cur_comp_info[] were set from SOS marker */

  int ci, mcublks, tmp;
  jpeg_component_info *compptr;
  
  if (cinfo->comps_in_scan == 1) {
    
    /* Noninterleaved (single-component) scan */
    compptr = cinfo->cur_comp_info[0];
    
    /* Overall image size in MCUs */
    cinfo->MCUs_per_row = compptr->width_in_blocks;
    cinfo->MCU_rows_in_scan = compptr->height_in_blocks;
    
    /* For noninterleaved scan, always one block per MCU */
    compptr->MCU_width = 1;
    compptr->MCU_height = 1;
    compptr->MCU_blocks = 1;
    compptr->MCU_sample_width = compptr->DCT_scaled_size;
    compptr->last_col_width = 1;
    /* For noninterleaved scans, it is convenient to define last_row_height
     * as the number of block rows present in the last iMCU row.
     */
    tmp = (int) (compptr->height_in_blocks % compptr->v_samp_factor);
    if (tmp == 0) tmp = compptr->v_samp_factor;
    compptr->last_row_height = tmp;
    
    /* Prepare array describing MCU composition */
    cinfo->blocks_in_MCU = 1;
    cinfo->MCU_membership[0] = 0;
    
  } else {
    
    /* Interleaved (multi-component) scan */
    if (cinfo->comps_in_scan <= 0 || cinfo->comps_in_scan > MAX_COMPS_IN_SCAN) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    
    /* Overall image size in MCUs */
    cinfo->MCUs_per_row = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_width,
		    (long) (cinfo->max_h_samp_factor*DCTSIZE));
    cinfo->MCU_rows_in_scan = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_height,
		    (long) (cinfo->max_v_samp_factor*DCTSIZE));
    
    cinfo->blocks_in_MCU = 0;
    
    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
      compptr = cinfo->cur_comp_info[ci];
      /* Sampling factors give # of blocks of component in each MCU */
      compptr->MCU_width = compptr->h_samp_factor;
      compptr->MCU_height = compptr->v_samp_factor;
      compptr->MCU_blocks = compptr->MCU_width * compptr->MCU_height;
      compptr->MCU_sample_width = compptr->MCU_width * compptr->DCT_scaled_size;
      /* Figure number of non-dummy blocks in last MCU column & row */
      tmp = (int) (compptr->width_in_blocks % compptr->MCU_width);
      if (tmp == 0) tmp = compptr->MCU_width;
      compptr->last_col_width = tmp;
      tmp = (int) (compptr->height_in_blocks % compptr->MCU_height);
      if (tmp == 0) tmp = compptr->MCU_height;
      compptr->last_row_height = tmp;
      /* Prepare array describing MCU composition */
      mcublks = compptr->MCU_blocks;
      if (cinfo->blocks_in_MCU + mcublks > D_MAX_BLOCKS_IN_MCU) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
		}
      while (mcublks-- > 0) {
	cinfo->MCU_membership[cinfo->blocks_in_MCU++] = ci;
      }
    }
    
  }
	return 0;
}


/*
 * Save away a copy of the Q-table referenced by each component present
 * in the current scan, unless already saved during a prior scan.
 *
 * In a multiple-scan JPEG file, the encoder could assign different components
 * the same Q-table slot number, but change table definitions between scans
 * so that each component uses a different Q-table.  (The IJG encoder is not
 * currently capable of doing this, but other encoders might.)  Since we want
 * to be able to dequantize all the components at the end of the file, this
 * means that we have to save away the table actually used for each component.
 * We do this by copying the table at the start of the first scan containing
 * the component.
 * The JPEG spec prohibits the encoder from changing the contents of a Q-table
 * slot between scans of a component using that slot.  If the encoder does so
 * anyway, this decoder will simply use the Q-table values that were current
 * at the start of the first scan for the component.
 *
 * The decompressor output side looks only at the saved quant tables,
 * not at the current Q-table slots.
 */

int latch_quant_tables (j_decompress_ptr cinfo) {

  int ci, qtblno;
  jpeg_component_info *compptr;
  JQUANT_TBL * qtbl;

  for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
    compptr = cinfo->cur_comp_info[ci];
    /* No work if we already saved Q-table for this component */
    if (compptr->quant_table != NULL)
      continue;
    /* Make sure specified quantization table is present */
    qtblno = compptr->quant_tbl_no;
    if (qtblno < 0 || qtblno >= NUM_QUANT_TBLS ||
	cinfo->quant_tbl_ptrs[qtblno] == NULL) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    /* OK, save away the quantization table */
    qtbl = (JQUANT_TBL *)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  SIZEOF(JQUANT_TBL));
    MEMCOPY(qtbl, cinfo->quant_tbl_ptrs[qtblno], SIZEOF(JQUANT_TBL));
    compptr->quant_table = qtbl;
  }
	return 0;
}


/*
 * Initialize the input modules to read a scan of compressed data.
 * The first call to this is done by jdmaster.c after initializing
 * the entire decompressor (during jpeg_start_decompress).
 * Subsequent calls come from consume_markers, below.
 */

int start_input_pass (j_decompress_ptr cinfo) {

  if( -1==per_scan_setup(cinfo) ) return -1;
  if( -1==latch_quant_tables(cinfo) ) return -1;
  if( -1==(*cinfo->entropy->start_pass) (cinfo) ) return -1;
  if( -1==(*cinfo->coef->start_input_pass) (cinfo) ) return -1;
  cinfo->inputctl->consume_input = cinfo->coef->consume_data;
  return 0;
}


/*
 * Finish up after inputting a compressed-data scan.
 * This is called by the coefficient controller after it's read all
 * the expected data of the scan.
 */

METHODDEF(void)
finish_input_pass (j_decompress_ptr cinfo)
{
  cinfo->inputctl->consume_input = consume_markers;
}


/*
 * Read JPEG markers before, between, or after compressed-data scans.
 * Change state as necessary when a new scan is reached.
 * Return value is JPEG_SUSPENDED, JPEG_REACHED_SOS, or JPEG_REACHED_EOI.
 *
 * The consume_input method pointer points either here or to the
 * coefficient controller's consume_data routine, depending on whether
 * we are reading a compressed data segment or inter-segment markers.
 */

int consume_markers (j_decompress_ptr cinfo) {

  my_inputctl_ptr inputctl = (my_inputctl_ptr) cinfo->inputctl;
  int val;

  if (inputctl->pub.eoi_reached) /* After hitting EOI, read no further */
    return JPEG_REACHED_EOI;

  val = (*cinfo->marker->read_markers) (cinfo);

  switch (val) {
  case JPEG_REACHED_SOS:	/* Found SOS */
    if (inputctl->inheaders) {	/* 1st SOS */
      if( -1==initial_setup(cinfo)) return -1;
      inputctl->inheaders = FALSE;
      /* Note: start_input_pass must be called by jdmaster.c
       * before any more input can be consumed.  jdapimin.c is
       * responsible for enforcing this sequencing.
       */
    } else {			/* 2nd or later SOS marker */
      if (! inputctl->pub.has_multiple_scans) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
      if( -1==start_input_pass(cinfo) ) return -1;
    }
    break;
  case JPEG_REACHED_EOI:	/* Found EOI */
    inputctl->pub.eoi_reached = TRUE;
    if (inputctl->inheaders) {	/* Tables-only datastream, apparently */
      if (cinfo->marker->saw_SOF) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
		}
    } else {
      /* Prevent infinite loop in coef ctlr's decompress_data routine
       * if user set output_scan_number larger than number of scans.
       */
      if (cinfo->output_scan_number > cinfo->input_scan_number)
	cinfo->output_scan_number = cinfo->input_scan_number;
    }
    break;
  case JPEG_SUSPENDED:
    break;
  }

  return val;
}


/*
 * Reset state to begin a fresh datastream.
 */

METHODDEF(void)
reset_input_controller (j_decompress_ptr cinfo)
{
  my_inputctl_ptr inputctl = (my_inputctl_ptr) cinfo->inputctl;

  inputctl->pub.consume_input = consume_markers;
  inputctl->pub.has_multiple_scans = FALSE; /* "unknown" would be better */
  inputctl->pub.eoi_reached = FALSE;
  inputctl->inheaders = TRUE;
  /* Reset other modules */
//  (*cinfo->err->reset_error_mgr) ((j_common_ptr) cinfo);
  (*cinfo->marker->reset_marker_reader) (cinfo);
  /* Reset progression state -- would be cleaner if entropy decoder did this */
  cinfo->coef_bits = NULL;
}


/*
 * Initialize the input controller module.
 * This is called only once, when the decompression object is created.
 */

GLOBAL(void)
jinit_input_controller (j_decompress_ptr cinfo)
{
  my_inputctl_ptr inputctl;

  /* Create subobject in permanent pool */
  inputctl = (my_inputctl_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
				SIZEOF(my_input_controller));
  cinfo->inputctl = (struct jpeg_input_controller *) inputctl;
  /* Initialize method pointers */
  inputctl->pub.consume_input = consume_markers;
  inputctl->pub.reset_input_controller = reset_input_controller;
  inputctl->pub.start_input_pass = start_input_pass;
  inputctl->pub.finish_input_pass = finish_input_pass;
  /* Initialize state: can't use reset_input_controller since we don't
   * want to try to reset other modules yet.
   */
  inputctl->pub.has_multiple_scans = FALSE; /* "unknown" would be better */
  inputctl->pub.eoi_reached = FALSE;
  inputctl->inheaders = TRUE;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdmainct.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the main buffer controller for decompression.
 * The main buffer lies between the JPEG decompressor proper and the
 * post-processor; it holds downsampled data in the JPEG colorspace.
 *
 * Note that this code is bypassed in raw-data mode, since the application
 * supplies the equivalent of the main buffer in that case.
 */

/*
 * In the current system design, the main buffer need never be a full-image
 * buffer; any full-height buffers will be found inside the coefficient or
 * postprocessing controllers.  Nonetheless, the main controller is not
 * trivial.  Its responsibility is to provide context rows for upsampling/
 * rescaling, and doing this in an efficient fashion is a bit tricky.
 *
 * Postprocessor input data is counted in "row groups".  A row group
 * is defined to be (v_samp_factor * DCT_scaled_size / min_DCT_scaled_size)
 * sample rows of each component.  (We require DCT_scaled_size values to be
 * chosen such that these numbers are integers.  In practice DCT_scaled_size
 * values will likely be powers of two, so we actually have the stronger
 * condition that DCT_scaled_size / min_DCT_scaled_size is an integer.)
 * Upsampling will typically produce max_v_samp_factor pixel rows from each
 * row group (times any additional scale factor that the upsampler is
 * applying).
 *
 * The coefficient controller will deliver data to us one iMCU row at a time;
 * each iMCU row contains v_samp_factor * DCT_scaled_size sample rows, or
 * exactly min_DCT_scaled_size row groups.  (This amount of data corresponds
 * to one row of MCUs when the image is fully interleaved.)  Note that the
 * number of sample rows varies across components, but the number of row
 * groups does not.  Some garbage sample rows may be included in the last iMCU
 * row at the bottom of the image.
 *
 * Depending on the vertical scaling algorithm used, the upsampler may need
 * access to the sample row(s) above and below its current input row group.
 * The upsampler is required to set need_context_rows TRUE at global selection
 * time if so.  When need_context_rows is FALSE, this controller can simply
 * obtain one iMCU row at a time from the coefficient controller and dole it
 * out as row groups to the postprocessor.
 *
 * When need_context_rows is TRUE, this controller guarantees that the buffer
 * passed to postprocessing contains at least one row group's worth of samples
 * above and below the row group(s) being processed.  Note that the context
 * rows "above" the first passed row group appear at negative row offsets in
 * the passed buffer.  At the top and bottom of the image, the required
 * context rows are manufactured by duplicating the first or last real sample
 * row; this avoids having special cases in the upsampling inner loops.
 *
 * The amount of context is fixed at one row group just because that's a
 * convenient number for this controller to work with.  The existing
 * upsamplers really only need one sample row of context.  An upsampler
 * supporting arbitrary output rescaling might wish for more than one row
 * group of context when shrinking the image; tough, we don't handle that.
 * (This is justified by the assumption that downsizing will be handled mostly
 * by adjusting the DCT_scaled_size values, so that the actual scale factor at
 * the upsample step needn't be much less than one.)
 *
 * To provide the desired context, we have to retain the last two row groups
 * of one iMCU row while reading in the next iMCU row.  (The last row group
 * can't be processed until we have another row group for its below-context,
 * and so we have to save the next-to-last group too for its above-context.)
 * We could do this most simply by copying data around in our buffer, but
 * that'd be very slow.  We can avoid copying any data by creating a rather
 * strange pointer structure.  Here's how it works.  We allocate a workspace
 * consisting of M+2 row groups (where M = min_DCT_scaled_size is the number
 * of row groups per iMCU row).  We create two sets of redundant pointers to
 * the workspace.  Labeling the physical row groups 0 to M+1, the synthesized
 * pointer lists look like this:
 *                   M+1                          M-1
 * master pointer --> 0         master pointer --> 0
 *                    1                            1
 *                   ...                          ...
 *                   M-3                          M-3
 *                   M-2                           M
 *                   M-1                          M+1
 *                    M                           M-2
 *                   M+1                          M-1
 *                    0                            0
 * We read alternate iMCU rows using each master pointer; thus the last two
 * row groups of the previous iMCU row remain un-overwritten in the workspace.
 * The pointer lists are set up so that the required context rows appear to
 * be adjacent to the proper places when we pass the pointer lists to the
 * upsampler.
 *
 * The above pictures describe the normal state of the pointer lists.
 * At top and bottom of the image, we diddle the pointer lists to duplicate
 * the first or last sample row as necessary (this is cheaper than copying
 * sample rows around).
 *
 * This scheme breaks down if M < 2, ie, min_DCT_scaled_size is 1.  In that
 * situation each iMCU row provides only one row group so the buffering logic
 * must be different (eg, we must read two iMCU rows before we can emit the
 * first row group).  For now, we simply do not support providing context
 * rows when min_DCT_scaled_size is 1.  That combination seems unlikely to
 * be worth providing --- if someone wants a 1/8th-size preview, they probably
 * want it quick and dirty, so a context-free upsampler is sufficient.
 */


/* Private buffer controller object */

typedef struct {
  struct jpeg_d_main_controller pub; /* public fields */

  /* Pointer to allocated workspace (M or M+2 row groups). */
  JSAMPARRAY buffer[MAX_COMPONENTS];

  boolean buffer_full;		/* Have we gotten an iMCU row from decoder? */
  JDIMENSION rowgroup_ctr;	/* counts row groups output to postprocessor */

  /* Remaining fields are only used in the context case. */

  /* These are the master pointers to the funny-order pointer lists. */
  JSAMPIMAGE xbuffer[2];	/* pointers to weird pointer lists */

  int whichptr;			/* indicates which pointer set is now in use */
  int context_state;		/* process_data state machine status */
  JDIMENSION rowgroups_avail;	/* row groups available to postprocessor */
  JDIMENSION iMCU_row_ctr;	/* counts iMCU rows to detect image top/bot */
} my_main_controller;

typedef my_main_controller * my_main_ptr;

/* context_state values: */
#define CTX_PREPARE_FOR_IMCU	0	/* need to prepare for MCU row */
#define CTX_PROCESS_IMCU	1	/* feeding iMCU to postprocessor */
#define CTX_POSTPONED_ROW	2	/* feeding postponed row group */


/* Forward declarations */
METHODDEF(void) process_data_simple_main
	JPP((j_decompress_ptr cinfo, JSAMPARRAY output_buf,
	     JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail));
METHODDEF(void) process_data_context_main
	JPP((j_decompress_ptr cinfo, JSAMPARRAY output_buf,
	     JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail));

LOCAL(void)
alloc_funny_pointers (j_decompress_ptr cinfo)
/* Allocate space for the funny pointer lists.
 * This is done only once, not once per pass.
 */
{
  my_main_ptr main = (my_main_ptr) cinfo->main;
  int ci, rgroup;
  int M = cinfo->min_DCT_scaled_size;
  jpeg_component_info *compptr;
  JSAMPARRAY xbuf;

  /* Get top-level space for component array pointers.
   * We alloc both arrays with one call to save a few cycles.
   */
  main->xbuffer[0] = (JSAMPIMAGE)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				cinfo->num_components * 2 * SIZEOF(JSAMPARRAY));
  main->xbuffer[1] = main->xbuffer[0] + cinfo->num_components;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) /
      cinfo->min_DCT_scaled_size; /* height of a row group of component */
    /* Get space for pointer lists --- M+4 row groups in each list.
     * We alloc both pointer lists with one call to save a few cycles.
     */
    xbuf = (JSAMPARRAY)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  2 * (rgroup * (M + 4)) * SIZEOF(JSAMPROW));
    xbuf += rgroup;		/* want one row group at negative offsets */
    main->xbuffer[0][ci] = xbuf;
    xbuf += rgroup * (M + 4);
    main->xbuffer[1][ci] = xbuf;
  }
}


LOCAL(void)
make_funny_pointers (j_decompress_ptr cinfo)
/* Create the funny pointer lists discussed in the comments above.
 * The actual workspace is already allocated (in main->buffer),
 * and the space for the pointer lists is allocated too.
 * This routine just fills in the curiously ordered lists.
 * This will be repeated at the beginning of each pass.
 */
{
  my_main_ptr main = (my_main_ptr) cinfo->main;
  int ci, i, rgroup;
  int M = cinfo->min_DCT_scaled_size;
  jpeg_component_info *compptr;
  JSAMPARRAY buf, xbuf0, xbuf1;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) /
      cinfo->min_DCT_scaled_size; /* height of a row group of component */
    xbuf0 = main->xbuffer[0][ci];
    xbuf1 = main->xbuffer[1][ci];
    /* First copy the workspace pointers as-is */
    buf = main->buffer[ci];
    for (i = 0; i < rgroup * (M + 2); i++) {
      xbuf0[i] = xbuf1[i] = buf[i];
    }
    /* In the second list, put the last four row groups in swapped order */
    for (i = 0; i < rgroup * 2; i++) {
      xbuf1[rgroup*(M-2) + i] = buf[rgroup*M + i];
      xbuf1[rgroup*M + i] = buf[rgroup*(M-2) + i];
    }
    /* The wraparound pointers at top and bottom will be filled later
     * (see set_wraparound_pointers, below).  Initially we want the "above"
     * pointers to duplicate the first actual data line.  This only needs
     * to happen in xbuffer[0].
     */
    for (i = 0; i < rgroup; i++) {
      xbuf0[i - rgroup] = xbuf0[0];
    }
  }
}


LOCAL(void)
set_wraparound_pointers (j_decompress_ptr cinfo)
/* Set up the "wraparound" pointers at top and bottom of the pointer lists.
 * This changes the pointer list state from top-of-image to the normal state.
 */
{
  my_main_ptr main = (my_main_ptr) cinfo->main;
  int ci, i, rgroup;
  int M = cinfo->min_DCT_scaled_size;
  jpeg_component_info *compptr;
  JSAMPARRAY xbuf0, xbuf1;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) /
      cinfo->min_DCT_scaled_size; /* height of a row group of component */
    xbuf0 = main->xbuffer[0][ci];
    xbuf1 = main->xbuffer[1][ci];
    for (i = 0; i < rgroup; i++) {
      xbuf0[i - rgroup] = xbuf0[rgroup*(M+1) + i];
      xbuf1[i - rgroup] = xbuf1[rgroup*(M+1) + i];
      xbuf0[rgroup*(M+2) + i] = xbuf0[i];
      xbuf1[rgroup*(M+2) + i] = xbuf1[i];
    }
  }
}


LOCAL(void)
set_bottom_pointers (j_decompress_ptr cinfo)
/* Change the pointer lists to duplicate the last sample row at the bottom
 * of the image.  whichptr indicates which xbuffer holds the final iMCU row.
 * Also sets rowgroups_avail to indicate number of nondummy row groups in row.
 */
{
  my_main_ptr main = (my_main_ptr) cinfo->main;
  int ci, i, rgroup, iMCUheight, rows_left;
  jpeg_component_info *compptr;
  JSAMPARRAY xbuf;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Count sample rows in one iMCU row and in one row group */
    iMCUheight = compptr->v_samp_factor * compptr->DCT_scaled_size;
    rgroup = iMCUheight / cinfo->min_DCT_scaled_size;
    /* Count nondummy sample rows remaining for this component */
    rows_left = (int) (compptr->downsampled_height % (JDIMENSION) iMCUheight);
    if (rows_left == 0) rows_left = iMCUheight;
    /* Count nondummy row groups.  Should get same answer for each component,
     * so we need only do it once.
     */
    if (ci == 0) {
      main->rowgroups_avail = (JDIMENSION) ((rows_left-1) / rgroup + 1);
    }
    /* Duplicate the last real sample row rgroup*2 times; this pads out the
     * last partial rowgroup and ensures at least one full rowgroup of context.
     */
    xbuf = main->xbuffer[main->whichptr][ci];
    for (i = 0; i < rgroup * 2; i++) {
      xbuf[rows_left + i] = xbuf[rows_left-1];
    }
  }
}


/*
 * Initialize for a processing pass.
 */

int start_pass_main (j_decompress_ptr cinfo, J_BUF_MODE pass_mode)
{
  my_main_ptr main = (my_main_ptr) cinfo->main;

  switch (pass_mode) {
  case JBUF_PASS_THRU:
    if (cinfo->upsample->need_context_rows) {
      main->pub.process_data = process_data_context_main;
      make_funny_pointers(cinfo); /* Create the xbuffer[] lists */
      main->whichptr = 0;	/* Read first iMCU row into xbuffer[0] */
      main->context_state = CTX_PREPARE_FOR_IMCU;
      main->iMCU_row_ctr = 0;
    } else {
      /* Simple case with no context needed */
      main->pub.process_data = process_data_simple_main;
    }
    main->buffer_full = FALSE;	/* Mark buffer empty */
    main->rowgroup_ctr = 0;
    break;
  default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
  }
  return 0;
}


/*
 * Process some data.
 * This handles the simple case where no context is required.
 */

METHODDEF(void)
process_data_simple_main (j_decompress_ptr cinfo,
			  JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
			  JDIMENSION out_rows_avail)
{
  my_main_ptr main = (my_main_ptr) cinfo->main;
  JDIMENSION rowgroups_avail;

  /* Read input data if we haven't filled the main buffer yet */
  if (! main->buffer_full) {
    if (! (*cinfo->coef->decompress_data) (cinfo, main->buffer))
      return;			/* suspension forced, can do nothing more */
    main->buffer_full = TRUE;	/* OK, we have an iMCU row to work with */
  }

  /* There are always min_DCT_scaled_size row groups in an iMCU row. */
  rowgroups_avail = (JDIMENSION) cinfo->min_DCT_scaled_size;
  /* Note: at the bottom of the image, we may pass extra garbage row groups
   * to the postprocessor.  The postprocessor has to check for bottom
   * of image anyway (at row resolution), so no point in us doing it too.
   */

  /* Feed the postprocessor */
  (*cinfo->post->post_process_data) (cinfo, main->buffer,
				     &main->rowgroup_ctr, rowgroups_avail,
				     output_buf, out_row_ctr, out_rows_avail);

  /* Has postprocessor consumed all the data yet? If so, mark buffer empty */
  if (main->rowgroup_ctr >= rowgroups_avail) {
    main->buffer_full = FALSE;
    main->rowgroup_ctr = 0;
  }
}


/*
 * Process some data.
 * This handles the case where context rows must be provided.
 */

METHODDEF(void)
process_data_context_main (j_decompress_ptr cinfo,
			   JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
			   JDIMENSION out_rows_avail)
{
  my_main_ptr main = (my_main_ptr) cinfo->main;

  /* Read input data if we haven't filled the main buffer yet */
  if (! main->buffer_full) {
    if (! (*cinfo->coef->decompress_data) (cinfo,
					   main->xbuffer[main->whichptr]))
      return;			/* suspension forced, can do nothing more */
    main->buffer_full = TRUE;	/* OK, we have an iMCU row to work with */
    main->iMCU_row_ctr++;	/* count rows received */
  }

  /* Postprocessor typically will not swallow all the input data it is handed
   * in one call (due to filling the output buffer first).  Must be prepared
   * to exit and restart.  This switch lets us keep track of how far we got.
   * Note that each case falls through to the next on successful completion.
   */
  switch (main->context_state) {
  case CTX_POSTPONED_ROW:
    /* Call postprocessor using previously set pointers for postponed row */
    (*cinfo->post->post_process_data) (cinfo, main->xbuffer[main->whichptr],
			&main->rowgroup_ctr, main->rowgroups_avail,
			output_buf, out_row_ctr, out_rows_avail);
    if (main->rowgroup_ctr < main->rowgroups_avail)
      return;			/* Need to suspend */
    main->context_state = CTX_PREPARE_FOR_IMCU;
    if (*out_row_ctr >= out_rows_avail)
      return;			/* Postprocessor exactly filled output buf */
    /*FALLTHROUGH*/
  case CTX_PREPARE_FOR_IMCU:
    /* Prepare to process first M-1 row groups of this iMCU row */
    main->rowgroup_ctr = 0;
    main->rowgroups_avail = (JDIMENSION) (cinfo->min_DCT_scaled_size - 1);
    /* Check for bottom of image: if so, tweak pointers to "duplicate"
     * the last sample row, and adjust rowgroups_avail to ignore padding rows.
     */
    if (main->iMCU_row_ctr == cinfo->total_iMCU_rows)
      set_bottom_pointers(cinfo);
    main->context_state = CTX_PROCESS_IMCU;
    /*FALLTHROUGH*/
  case CTX_PROCESS_IMCU:
    /* Call postprocessor using previously set pointers */
    (*cinfo->post->post_process_data) (cinfo, main->xbuffer[main->whichptr],
			&main->rowgroup_ctr, main->rowgroups_avail,
			output_buf, out_row_ctr, out_rows_avail);
    if (main->rowgroup_ctr < main->rowgroups_avail)
      return;			/* Need to suspend */
    /* After the first iMCU, change wraparound pointers to normal state */
    if (main->iMCU_row_ctr == 1)
      set_wraparound_pointers(cinfo);
    /* Prepare to load new iMCU row using other xbuffer list */
    main->whichptr ^= 1;	/* 0=>1 or 1=>0 */
    main->buffer_full = FALSE;
    /* Still need to process last row group of this iMCU row, */
    /* which is saved at index M+1 of the other xbuffer */
    main->rowgroup_ctr = (JDIMENSION) (cinfo->min_DCT_scaled_size + 1);
    main->rowgroups_avail = (JDIMENSION) (cinfo->min_DCT_scaled_size + 2);
    main->context_state = CTX_POSTPONED_ROW;
  }
}


/*
 * Initialize main buffer controller.
 */

int jinit_d_main_controller (j_decompress_ptr cinfo, boolean need_full_buffer) {

  my_main_ptr main;
  int ci, rgroup, ngroups;
  jpeg_component_info *compptr;

  main = (my_main_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_main_controller));
  cinfo->main = (struct jpeg_d_main_controller *) main;
  main->pub.start_pass = start_pass_main;

	if (need_full_buffer)	{	/* shouldn't happen */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* Allocate the workspace.
   * ngroups is the number of row groups we need.
   */
  if (cinfo->upsample->need_context_rows) {
    if (cinfo->min_DCT_scaled_size < 2) {/* unsupported, see comments above */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
    alloc_funny_pointers(cinfo); /* Alloc space for xbuffer[] lists */
    ngroups = cinfo->min_DCT_scaled_size + 2;
  } else {
    ngroups = cinfo->min_DCT_scaled_size;
  }

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) /
      cinfo->min_DCT_scaled_size; /* height of a row group of component */
    main->buffer[ci] = (*cinfo->mem->alloc_sarray)
			((j_common_ptr) cinfo, JPOOL_IMAGE,
			 compptr->width_in_blocks * compptr->DCT_scaled_size,
			 (JDIMENSION) (rgroup * ngroups));
  }
	return 0;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdmarker.c
 *
 * Copyright (C) 1991-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains routines to decode JPEG datastream markers.
 * Most of the complexity arises from our desire to support input
 * suspension: if not all of the data for a marker is available,
 * we must exit back to the application.  On resumption, we reprocess
 * the marker.
 */

#define MAKESTMT(stuff)		do { stuff } while (0)


typedef enum {			/* JPEG marker codes */
  M_SOF0  = 0xc0,
  M_SOF1  = 0xc1,
  M_SOF2  = 0xc2,
  M_SOF3  = 0xc3,
  
  M_SOF5  = 0xc5,
  M_SOF6  = 0xc6,
  M_SOF7  = 0xc7,
  
  M_JPG   = 0xc8,
  M_SOF9  = 0xc9,
  M_SOF10 = 0xca,
  M_SOF11 = 0xcb,
  
  M_SOF13 = 0xcd,
  M_SOF14 = 0xce,
  M_SOF15 = 0xcf,
  
  M_DHT   = 0xc4,
  
  M_DAC   = 0xcc,
  
  M_RST0  = 0xd0,
  M_RST1  = 0xd1,
  M_RST2  = 0xd2,
  M_RST3  = 0xd3,
  M_RST4  = 0xd4,
  M_RST5  = 0xd5,
  M_RST6  = 0xd6,
  M_RST7  = 0xd7,
  
  M_SOI   = 0xd8,
  M_EOI   = 0xd9,
  M_SOS   = 0xda,
  M_DQT   = 0xdb,
  M_DNL   = 0xdc,
  M_DRI   = 0xdd,
  M_DHP   = 0xde,
  M_EXP   = 0xdf,
  
  M_APP0  = 0xe0,
  M_APP1  = 0xe1,
  M_APP2  = 0xe2,
  M_APP3  = 0xe3,
  M_APP4  = 0xe4,
  M_APP5  = 0xe5,
  M_APP6  = 0xe6,
  M_APP7  = 0xe7,
  M_APP8  = 0xe8,
  M_APP9  = 0xe9,
  M_APP10 = 0xea,
  M_APP11 = 0xeb,
  M_APP12 = 0xec,
  M_APP13 = 0xed,
  M_APP14 = 0xee,
  M_APP15 = 0xef,
  
  M_JPG0  = 0xf0,
  M_JPG13 = 0xfd,
  M_COM   = 0xfe,
  
  M_TEM   = 0x01,
  
  M_ERROR = 0x100
} JPEG_MARKER;


/* Private state */

typedef struct {
  struct jpeg_marker_reader pub; /* public fields */

  /* Application-overridable marker processing methods */
  jpeg_marker_parser_method process_COM;
  jpeg_marker_parser_method process_APPn[16];

  /* Limit on marker data length to save for each marker type */
  unsigned int length_limit_COM;
  unsigned int length_limit_APPn[16];

  /* Status of COM/APPn marker saving */
  jpeg_saved_marker_ptr cur_marker;	/* NULL if not processing a marker */
  unsigned int bytes_read;		/* data bytes read so far in marker */
  /* Note: cur_marker is not linked into marker_list until it's all read. */
} my_marker_reader;

typedef my_marker_reader * my_marker_ptr;


/*
 * Macros for fetching data from the data source module.
 *
 * At all times, cinfo->src->next_input_byte and ->bytes_in_buffer reflect
 * the current restart point; we update them only when we have reached a
 * suitable place to restart if a suspension occurs.
 */

/* Declare and initialize local copies of input pointer/count */
#define INPUT_VARS(cinfo)  \
	struct jpeg_source_mgr * datasrc = (cinfo)->src;  \
	const JOCTET * next_input_byte = datasrc->next_input_byte;  \
	size_t bytes_in_buffer = datasrc->bytes_in_buffer

/* Unload the local copies --- do this only at a restart boundary */
#define INPUT_SYNC(cinfo)  \
	( datasrc->next_input_byte = next_input_byte,  \
	  datasrc->bytes_in_buffer = bytes_in_buffer )

/* Reload the local copies --- used only in MAKE_BYTE_AVAIL */
#define INPUT_RELOAD(cinfo)  \
	( next_input_byte = datasrc->next_input_byte,  \
	  bytes_in_buffer = datasrc->bytes_in_buffer )

/* Internal macro for INPUT_BYTE and INPUT_2BYTES: make a byte available.
 * Note we do *not* do INPUT_SYNC before calling fill_input_buffer,
 * but we must reload the local copies after a successful fill.
 */
#define MAKE_BYTE_AVAIL(cinfo,action)  \
	if (bytes_in_buffer == 0) {  \
	  if (! (*datasrc->fill_input_buffer) (cinfo))  \
	    { action; }  \
	  INPUT_RELOAD(cinfo);  \
	}

/* Read a byte into variable V.
 * If must suspend, take the specified action (typically "return FALSE").
 */
#define INPUT_BYTE(cinfo,V,action)  \
	MAKESTMT( MAKE_BYTE_AVAIL(cinfo,action); \
		  bytes_in_buffer--; \
		  V = GETJOCTET(*next_input_byte++); )

/* As above, but read two bytes interpreted as an unsigned 16-bit integer.
 * V should be declared unsigned int or perhaps INT32.
 */
#define INPUT_2BYTES(cinfo,V,action)  \
	MAKESTMT( MAKE_BYTE_AVAIL(cinfo,action); \
		  bytes_in_buffer--; \
		  V = ((unsigned int) GETJOCTET(*next_input_byte++)) << 8; \
		  MAKE_BYTE_AVAIL(cinfo,action); \
		  bytes_in_buffer--; \
		  V += GETJOCTET(*next_input_byte++); )


/*
 * Routines to process JPEG markers.
 *
 * Entry condition: JPEG marker itself has been read and its code saved
 *   in cinfo->unread_marker; input restart point is just after the marker.
 *
 * Exit: if return TRUE, have read and processed any parameters, and have
 *   updated the restart point to point after the parameters.
 *   If return FALSE, was forced to suspend before reaching end of
 *   marker parameters; restart point has not been moved.  Same routine
 *   will be called again after application supplies more input data.
 *
 * This approach to suspension assumes that all of a marker's parameters
 * can fit into a single input bufferload.  This should hold for "normal"
 * markers.  Some COM/APPn markers might have large parameter segments
 * that might not fit.  If we are simply dropping such a marker, we use
 * skip_input_data to get past it, and thereby put the problem on the
 * source manager's shoulders.  If we are saving the marker's contents
 * into memory, we use a slightly different convention: when forced to
 * suspend, the marker processor updates the restart point to the end of
 * what it's consumed (ie, the end of the buffer) before returning FALSE.
 * On resumption, cinfo->unread_marker still contains the marker code,
 * but the data source will point to the next chunk of marker data.
 * The marker processor must retain internal state to deal with this.
 *
 * Note that we don't bother to avoid duplicate trace messages if a
 * suspension occurs within marker parameters.  Other side effects
 * require more care.
 */


int get_soi(j_decompress_ptr cinfo) {
/* Process an SOI marker */

  int i;
  
//  TRACEMS(cinfo, 1, JTRC_SOI);

  if (cinfo->marker->saw_SOI) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* Reset all parameters that are defined to be reset by SOI */

  for (i = 0; i < NUM_ARITH_TBLS; i++) {
    cinfo->arith_dc_L[i] = 0;
    cinfo->arith_dc_U[i] = 1;
    cinfo->arith_ac_K[i] = 5;
  }
  cinfo->restart_interval = 0;

  /* Set initial assumptions for colorspace etc */

  cinfo->jpeg_color_space = JCS_UNKNOWN;
  cinfo->CCIR601_sampling = FALSE; /* Assume non-CCIR sampling??? */

  cinfo->saw_JFIF_marker = FALSE;
  cinfo->JFIF_major_version = 1; /* set default JFIF APP0 values */
  cinfo->JFIF_minor_version = 1;
  cinfo->density_unit = 0;
  cinfo->X_density = 1;
  cinfo->Y_density = 1;
  cinfo->saw_Adobe_marker = FALSE;
  cinfo->Adobe_transform = 0;

  cinfo->marker->saw_SOI = TRUE;

  return TRUE;
}


int get_sof (j_decompress_ptr cinfo, boolean is_prog, boolean is_arith) {
/* Process a SOFn marker */

  INT32 length;
  int c, ci;
  jpeg_component_info * compptr;
  INPUT_VARS(cinfo);

  cinfo->progressive_mode = is_prog;
  cinfo->arith_code = is_arith;

  INPUT_2BYTES(cinfo, length, return FALSE);

  INPUT_BYTE(cinfo, cinfo->data_precision, return FALSE);
  INPUT_2BYTES(cinfo, cinfo->image_height, return FALSE);
  INPUT_2BYTES(cinfo, cinfo->image_width, return FALSE);
  INPUT_BYTE(cinfo, cinfo->num_components, return FALSE);

  length -= 8;

	if(cinfo->marker->saw_SOF) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
    }

  /* We don't support files in which the image height is initially specified */
  /* as 0 and is later redefined by DNL.  As long as we have to check that,  */
  /* might as well have a general sanity check. */
  if (cinfo->image_height <= 0 || cinfo->image_width <= 0 || cinfo->num_components <= 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

	if (length != (cinfo->num_components * 3)) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  if (cinfo->comp_info == NULL)	/* do only once, even if suspend */
    cinfo->comp_info = (jpeg_component_info *) (*cinfo->mem->alloc_small)
			((j_common_ptr) cinfo, JPOOL_IMAGE,
			 cinfo->num_components * SIZEOF(jpeg_component_info));
  
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    compptr->component_index = ci;
    INPUT_BYTE(cinfo, compptr->component_id, return FALSE);
    INPUT_BYTE(cinfo, c, return FALSE);
    compptr->h_samp_factor = (c >> 4) & 15;
    compptr->v_samp_factor = (c     ) & 15;
    INPUT_BYTE(cinfo, compptr->quant_tbl_no, return FALSE);

  }

  cinfo->marker->saw_SOF = TRUE;

  INPUT_SYNC(cinfo);
  return TRUE;
}


int get_sos (j_decompress_ptr cinfo) {
/* Process a SOS marker */

  INT32 length;
  int i, ci, n, c, cc;
  jpeg_component_info * compptr;
  INPUT_VARS(cinfo);

	if (! cinfo->marker->saw_SOF) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  INPUT_2BYTES(cinfo, length, return FALSE);

  INPUT_BYTE(cinfo, n, return FALSE); /* Number of components */

  TRACEMS1(cinfo, 1, JTRC_SOS, n);

  if (length != (n * 2 + 6) || n < 1 || n > MAX_COMPS_IN_SCAN) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  cinfo->comps_in_scan = n;

  /* Collect the component-spec parameters */

  for (i = 0; i < n; i++) {
    INPUT_BYTE(cinfo, cc, return FALSE);
    INPUT_BYTE(cinfo, c, return FALSE);
    
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
	 ci++, compptr++) {
      if (cc == compptr->component_id)
	goto id_found;
    }

		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;

  id_found:

    cinfo->cur_comp_info[i] = compptr;
    compptr->dc_tbl_no = (c >> 4) & 15;
    compptr->ac_tbl_no = (c     ) & 15;
    
  }

  /* Collect the additional scan parameters Ss, Se, Ah/Al. */
  INPUT_BYTE(cinfo, c, return FALSE);
  cinfo->Ss = c;
  INPUT_BYTE(cinfo, c, return FALSE);
  cinfo->Se = c;
  INPUT_BYTE(cinfo, c, return FALSE);
  cinfo->Ah = (c >> 4) & 15;
  cinfo->Al = (c     ) & 15;

  /* Prepare to scan data & restart markers */
  cinfo->marker->next_restart_num = 0;

  /* Count another SOS marker */
  cinfo->input_scan_number++;

  INPUT_SYNC(cinfo);
  return TRUE;
}



#define get_dac(cinfo)  skip_variable(cinfo)


int get_dht (j_decompress_ptr cinfo) {
/* Process a DHT marker */

  INT32 length;
  UINT8 bits[17];
  UINT8 huffval[256];
  int i, index, count;
  JHUFF_TBL **htblptr;
  INPUT_VARS(cinfo);

  INPUT_2BYTES(cinfo, length, return FALSE);
  length -= 2;
  
  while (length > 16) {
    INPUT_BYTE(cinfo, index, return FALSE);

    bits[0] = 0;
    count = 0;
    for (i = 1; i <= 16; i++) {
      INPUT_BYTE(cinfo, bits[i], return FALSE);
      count += bits[i];
    }

    length -= 1 + 16;

    /* Here we just do minimal validation of the counts to avoid walking
     * off the end of our table space.  jdhuff.c will check more carefully.
     */
    if (count > 256 || ((INT32) count) > length) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

    for (i = 0; i < count; i++)
      INPUT_BYTE(cinfo, huffval[i], return FALSE);

    length -= count;

    if (index & 0x10) {		/* AC table definition */
      index -= 0x10;
      htblptr = &cinfo->ac_huff_tbl_ptrs[index];
    } else {			/* DC table definition */
      htblptr = &cinfo->dc_huff_tbl_ptrs[index];
    }

    if (index < 0 || index >= NUM_HUFF_TBLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

    if (*htblptr == NULL)
      *htblptr = jpeg_alloc_huff_table((j_common_ptr) cinfo);
  
    MEMCOPY((*htblptr)->bits, bits, SIZEOF((*htblptr)->bits));
    MEMCOPY((*htblptr)->huffval, huffval, SIZEOF((*htblptr)->huffval));
  }

  if (length != 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  INPUT_SYNC(cinfo);
  return TRUE;
}


int get_dqt (j_decompress_ptr cinfo) {
/* Process a DQT marker */

  INT32 length;
  int n, i, prec;
  unsigned int tmp;
  JQUANT_TBL *quant_ptr;
  INPUT_VARS(cinfo);

  INPUT_2BYTES(cinfo, length, return FALSE);
  length -= 2;

  while (length > 0) {
    INPUT_BYTE(cinfo, n, return FALSE);
    prec = n >> 4;
    n &= 0x0F;

    if (n >= NUM_QUANT_TBLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	  }
      
    if (cinfo->quant_tbl_ptrs[n] == NULL)
      cinfo->quant_tbl_ptrs[n] = jpeg_alloc_quant_table((j_common_ptr) cinfo);
    quant_ptr = cinfo->quant_tbl_ptrs[n];

    for (i = 0; i < DCTSIZE2; i++) {
      if (prec)
	INPUT_2BYTES(cinfo, tmp, return FALSE);
      else
	INPUT_BYTE(cinfo, tmp, return FALSE);
      /* We convert the zigzag-order table to natural array order. */
      quant_ptr->quantval[jpeg_natural_order[i]] = (UINT16) tmp;
    }

    length -= DCTSIZE2+1;
    if (prec) length -= DCTSIZE2;
  }

  if (length != 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  INPUT_SYNC(cinfo);
  return TRUE;
}


int get_dri (j_decompress_ptr cinfo) {
/* Process a DRI marker */

  INT32 length;
  unsigned int tmp;
  INPUT_VARS(cinfo);

  INPUT_2BYTES(cinfo, length, return FALSE);
  
  if (length != 4) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  INPUT_2BYTES(cinfo, tmp, return FALSE);

  cinfo->restart_interval = tmp;

  INPUT_SYNC(cinfo);
  return TRUE;
}


/*
 * Routines for processing APPn and COM markers.
 * These are either saved in memory or discarded, per application request.
 * APP0 and APP14 are specially checked to see if they are
 * JFIF and Adobe markers, respectively.
 */

#define APP0_DATA_LEN	14	/* Length of interesting data in APP0 */
#define APP14_DATA_LEN	12	/* Length of interesting data in APP14 */
#define APPN_DATA_LEN	14	/* Must be the largest of the above!! */


LOCAL(void)
examine_app0 (j_decompress_ptr cinfo, JOCTET  * data,
	      unsigned int datalen, INT32 remaining)
/* Examine first few bytes from an APP0.
 * Take appropriate action if it is a JFIF marker.
 * datalen is # of bytes at data[], remaining is length of rest of marker data.
 */
{
  INT32 totallen = (INT32) datalen + remaining;

  if (datalen >= APP0_DATA_LEN &&
      GETJOCTET(data[0]) == 0x4A &&
      GETJOCTET(data[1]) == 0x46 &&
      GETJOCTET(data[2]) == 0x49 &&
      GETJOCTET(data[3]) == 0x46 &&
      GETJOCTET(data[4]) == 0) {
    /* Found JFIF APP0 marker: save info */
    cinfo->saw_JFIF_marker = TRUE;
    cinfo->JFIF_major_version = GETJOCTET(data[5]);
    cinfo->JFIF_minor_version = GETJOCTET(data[6]);
    cinfo->density_unit = GETJOCTET(data[7]);
    cinfo->X_density = (GETJOCTET(data[8]) << 8) + GETJOCTET(data[9]);
    cinfo->Y_density = (GETJOCTET(data[10]) << 8) + GETJOCTET(data[11]);
    /* Check version.
     * Major version must be 1, anything else signals an incompatible change.
     * (We used to treat this as an error, but now it's a nonfatal warning,
     * because some bozo at Hijaak couldn't read the spec.)
     * Minor version should be 0..2, but process anyway if newer.
     */
    if (cinfo->JFIF_major_version != 1) {
//      WARNMS2(cinfo, JWRN_JFIF_MAJOR,
//	      cinfo->JFIF_major_version, cinfo->JFIF_minor_version);
	}
    /* Generate trace messages */
    TRACEMS5(cinfo, 1, JTRC_JFIF,
	     cinfo->JFIF_major_version, cinfo->JFIF_minor_version,
	     cinfo->X_density, cinfo->Y_density, cinfo->density_unit);
    /* Validate thumbnail dimensions and issue appropriate messages */
    if (GETJOCTET(data[12]) | GETJOCTET(data[13]))
      TRACEMS2(cinfo, 1, JTRC_JFIF_THUMBNAIL,
	       GETJOCTET(data[12]), GETJOCTET(data[13]));
    totallen -= APP0_DATA_LEN;
    if (totallen !=
	((INT32)GETJOCTET(data[12]) * (INT32)GETJOCTET(data[13]) * (INT32) 3))
      TRACEMS1(cinfo, 1, JTRC_JFIF_BADTHUMBNAILSIZE, (int) totallen);
  } else if (datalen >= 6 &&
      GETJOCTET(data[0]) == 0x4A &&
      GETJOCTET(data[1]) == 0x46 &&
      GETJOCTET(data[2]) == 0x58 &&
      GETJOCTET(data[3]) == 0x58 &&
      GETJOCTET(data[4]) == 0) {
    /* Found JFIF "JFXX" extension APP0 marker */
    /* The library doesn't actually do anything with these,
     * but we try to produce a helpful trace message.
     */
    switch (GETJOCTET(data[5])) {
    case 0x10:
      TRACEMS1(cinfo, 1, JTRC_THUMB_JPEG, (int) totallen);
      break;
    case 0x11:
      TRACEMS1(cinfo, 1, JTRC_THUMB_PALETTE, (int) totallen);
      break;
    case 0x13:
      TRACEMS1(cinfo, 1, JTRC_THUMB_RGB, (int) totallen);
      break;
    default:
      TRACEMS2(cinfo, 1, JTRC_JFIF_EXTENSION,
	       GETJOCTET(data[5]), (int) totallen);
      break;
    }
  } else {
    /* Start of APP0 does not match "JFIF" or "JFXX", or too short */
    TRACEMS1(cinfo, 1, JTRC_APP0, (int) totallen);
  }
}


LOCAL(void)
examine_app14 (j_decompress_ptr cinfo, JOCTET  * data,
	       unsigned int datalen, INT32 remaining)
/* Examine first few bytes from an APP14.
 * Take appropriate action if it is an Adobe marker.
 * datalen is # of bytes at data[], remaining is length of rest of marker data.
 */
{
  unsigned int version, flags0, flags1, transform;

  if (datalen >= APP14_DATA_LEN &&
      GETJOCTET(data[0]) == 0x41 &&
      GETJOCTET(data[1]) == 0x64 &&
      GETJOCTET(data[2]) == 0x6F &&
      GETJOCTET(data[3]) == 0x62 &&
      GETJOCTET(data[4]) == 0x65) {
    /* Found Adobe APP14 marker */
    version = (GETJOCTET(data[5]) << 8) + GETJOCTET(data[6]);
    flags0 = (GETJOCTET(data[7]) << 8) + GETJOCTET(data[8]);
    flags1 = (GETJOCTET(data[9]) << 8) + GETJOCTET(data[10]);
    transform = GETJOCTET(data[11]);
    TRACEMS4(cinfo, 1, JTRC_ADOBE, version, flags0, flags1, transform);
    cinfo->saw_Adobe_marker = TRUE;
    cinfo->Adobe_transform = (UINT8) transform;
  } else {
    /* Start of APP14 does not match "Adobe", or too short */
    TRACEMS1(cinfo, 1, JTRC_APP14, (int) (datalen + remaining));
  }
}


int get_interesting_appn (j_decompress_ptr cinfo) {
/* Process an APP0 or APP14 marker without saving it */

  INT32 length;
  JOCTET b[APPN_DATA_LEN];
  unsigned int i, numtoread;
  INPUT_VARS(cinfo);

  INPUT_2BYTES(cinfo, length, return FALSE);
  length -= 2;

  /* get the interesting part of the marker data */
  if (length >= APPN_DATA_LEN)
    numtoread = APPN_DATA_LEN;
  else if (length > 0)
    numtoread = (unsigned int) length;
  else
    numtoread = 0;
  for (i = 0; i < numtoread; i++)
    INPUT_BYTE(cinfo, b[i], return FALSE);
  length -= numtoread;

  /* process it */
  switch (cinfo->unread_marker) {
  case M_APP0:
    examine_app0(cinfo, (JOCTET  *) b, numtoread, length);
    break;
  case M_APP14:
    examine_app14(cinfo, (JOCTET  *) b, numtoread, length);
    break;
  default:
    /* can't get here unless jpeg_save_markers chooses wrong processor */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
  }

  /* skip any remaining data -- could be lots */
  INPUT_SYNC(cinfo);
  if (length > 0) (*cinfo->src->skip_input_data) (cinfo, (long) length);

  return TRUE;
}

int skip_variable (j_decompress_ptr cinfo) {
/* Skip over an unknown or uninteresting variable-length marker */

  INT32 length;
  INPUT_VARS(cinfo);

  INPUT_2BYTES(cinfo, length, return FALSE);
  length -= 2;
  
  INPUT_SYNC(cinfo);		/* do before skip_input_data */
  if (length > 0) (*cinfo->src->skip_input_data) (cinfo, (long) length);

  return TRUE;
}


/*
 * Find the next JPEG marker, save it in cinfo->unread_marker.
 * Returns FALSE if had to suspend before reaching a marker;
 * in that case cinfo->unread_marker is unchanged.
 *
 * Note that the result might not be a valid marker code,
 * but it will never be 0 or FF.
 */

LOCAL(boolean)
next_marker (j_decompress_ptr cinfo)
{
  int c;
  INPUT_VARS(cinfo);

  for (;;) {
    INPUT_BYTE(cinfo, c, return FALSE);
    /* Skip any non-FF bytes.
     * This may look a bit inefficient, but it will not occur in a valid file.
     * We sync after each discarded byte so that a suspending data source
     * can discard the byte from its buffer.
     */
    while (c != 0xFF) {
      cinfo->marker->discarded_bytes++;
      INPUT_SYNC(cinfo);
      INPUT_BYTE(cinfo, c, return FALSE);
    }
    /* This loop swallows any duplicate FF bytes.  Extra FFs are legal as
     * pad bytes, so don't count them in discarded_bytes.  We assume there
     * will not be so many consecutive FF bytes as to overflow a suspending
     * data source's input buffer.
     */
    do {
      INPUT_BYTE(cinfo, c, return FALSE);
    } while (c == 0xFF);
    if (c != 0)
      break;			/* found a valid marker, exit loop */
    /* Reach here if we found a stuffed-zero data sequence (FF/00).
     * Discard it and loop back to try again.
     */
    cinfo->marker->discarded_bytes += 2;
    INPUT_SYNC(cinfo);
  }

  if (cinfo->marker->discarded_bytes != 0) {
//    WARNMS2(cinfo, JWRN_EXTRANEOUS_DATA, cinfo->marker->discarded_bytes, c);
    cinfo->marker->discarded_bytes = 0;
  }

  cinfo->unread_marker = c;

  INPUT_SYNC(cinfo);
  return TRUE;
}


int first_marker (j_decompress_ptr cinfo)
/* Like next_marker, but used to obtain the initial SOI marker. */
/* For this marker, we do not allow preceding garbage or fill; otherwise,
 * we might well scan an entire input file before realizing it ain't JPEG.
 * If an application wants to process non-JFIF files, it must seek to the
 * SOI before calling the JPEG library.
 */
{
  int c, c2;
  INPUT_VARS(cinfo);

  INPUT_BYTE(cinfo, c, return FALSE);
  INPUT_BYTE(cinfo, c2, return FALSE);
  if (c != 0xFF || c2 != (int) M_SOI) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  cinfo->unread_marker = c2;

  INPUT_SYNC(cinfo);
  return TRUE;
}


/*
 * Read markers until SOS or EOI.
 *
 * Returns same codes as are defined for jpeg_consume_input:
 * JPEG_SUSPENDED, JPEG_REACHED_SOS, or JPEG_REACHED_EOI.
 */

int read_markers (j_decompress_ptr cinfo) {

	int retval;
  /* Outer loop repeats once for each marker. */
  for (;;) {
    /* Collect the marker proper, unless we already did. */
    /* NB: first_marker() enforces the requirement that SOI appear first. */
		if (cinfo->unread_marker == 0) {
			if (! cinfo->marker->saw_SOI) {
				if ( (retval=first_marker(cinfo)) <=0 ) {
					if( retval ) return -1;
					return JPEG_SUSPENDED;
				}
			} else {
				if (! next_marker(cinfo)) return JPEG_SUSPENDED;
			}
		}
    /* At this point cinfo->unread_marker contains the marker code and the
     * input point is just past the marker proper, but before any parameters.
     * A suspension will cause us to return with this state still true.
     */
    switch (cinfo->unread_marker) {
    case M_SOI:
      if ( -1==get_soi(cinfo) ) return -1;
      break;

    case M_SOF0:		/* Baseline */
    case M_SOF1:		/* Extended sequential, Huffman */
		if( (retval=get_sof(cinfo, FALSE, FALSE)) <= 0 ) {
			if( retval ) return -1;
			else return JPEG_SUSPENDED;
		}
		break;
    case M_SOF2:		/* Progressive, Huffman */
		if( (retval=get_sof(cinfo, TRUE, FALSE)) <= 0 ) {
			if( retval ) return -1;
			else return JPEG_SUSPENDED;
		}
		break;
    case M_SOF9:		/* Extended sequential, arithmetic */
		if( (retval=get_sof(cinfo, FALSE, TRUE)) <= 0 ) {
			if( retval ) return -1;
			else return JPEG_SUSPENDED;
		}
		break;
    case M_SOF10:		/* Progressive, arithmetic */
		if( (retval=get_sof(cinfo, TRUE, TRUE)) <= 0 ) {
			if( retval ) return -1;
			else return JPEG_SUSPENDED;
		}
		break;
    /* Currently unsupported SOFn types */
    case M_SOF3:		/* Lossless, Huffman */
    case M_SOF5:		/* Differential sequential, Huffman */
    case M_SOF6:		/* Differential progressive, Huffman */
    case M_SOF7:		/* Differential lossless, Huffman */
    case M_JPG:			/* Reserved for JPEG extensions */
    case M_SOF11:		/* Lossless, arithmetic */
    case M_SOF13:		/* Differential sequential, arithmetic */
    case M_SOF14:		/* Differential progressive, arithmetic */
    case M_SOF15:		/* Differential lossless, arithmetic */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
    case M_SOS:
		if( (retval=get_sos(cinfo)) <= 0 ) {
			if( retval ) return -1;
			return JPEG_SUSPENDED;
		}
      cinfo->unread_marker = 0;	/* processed the marker */
      return JPEG_REACHED_SOS;
    case M_EOI:
      cinfo->unread_marker = 0;	/* processed the marker */
      return JPEG_REACHED_EOI;
      
    case M_DAC:
      if (! get_dac(cinfo))
	return JPEG_SUSPENDED;
      break;
      
    case M_DHT:
		if( (retval=get_dht(cinfo)) <=0 ) {
			if( retval ) return -1;
			return JPEG_SUSPENDED;
		}
		break;
    case M_DQT:
      if( (retval=get_dqt(cinfo)) <=0 ) {
		if( retval ) return -1;
		return JPEG_SUSPENDED;
		}
		break;
    case M_DRI:
      if( (retval=get_dri(cinfo)) <= 0 ) {
		if( retval ) return -1;
		return JPEG_SUSPENDED;
		}
		break;
    case M_APP0:
    case M_APP1:
    case M_APP2:
    case M_APP3:
    case M_APP4:
    case M_APP5:
    case M_APP6:
    case M_APP7:
    case M_APP8:
    case M_APP9:
    case M_APP10:
    case M_APP11:
    case M_APP12:
    case M_APP13:
    case M_APP14:
    case M_APP15:
      if (! (*((my_marker_ptr) cinfo->marker)->process_APPn[cinfo->unread_marker - (int) M_APP0]) (cinfo)) return JPEG_SUSPENDED;
      break;
    case M_COM:
      if (! (*((my_marker_ptr) cinfo->marker)->process_COM) (cinfo))
	return JPEG_SUSPENDED;
      break;
    case M_RST0:		/* these are all parameterless */
    case M_RST1:
    case M_RST2:
    case M_RST3:
    case M_RST4:
    case M_RST5:
    case M_RST6:
    case M_RST7:
    case M_TEM:
      break;
    case M_DNL:			/* Ignore DNL ... perhaps the wrong thing */
      if (! skip_variable(cinfo)) return JPEG_SUSPENDED;
      break;
    default:			/* must be DHP, EXP, JPGn, or RESn */
      /* For now, we treat the reserved markers as fatal errors since they are
       * likely to be used to signal incompatible JPEG Part 3 extensions.
       * Once the JPEG 3 version-number marker is well defined, this code
       * ought to change!
       */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
    }
    /* Successfully processed marker, so reset state variable */
    cinfo->unread_marker = 0;
  } /* end loop */
}


/*
 * Read a restart marker, which is expected to appear next in the datastream;
 * if the marker is not there, take appropriate recovery action.
 * Returns FALSE if suspension is required.
 *
 * This is called by the entropy decoder after it has read an appropriate
 * number of MCUs.  cinfo->unread_marker may be nonzero if the entropy decoder
 * has already read a marker from the data source.  Under normal conditions
 * cinfo->unread_marker will be reset to 0 before returning; if not reset,
 * it holds a marker which the decoder will be unable to read past.
 */

int read_restart_marker (j_decompress_ptr cinfo)
{
  /* Obtain a marker unless we already did. */
  /* Note that next_marker will complain if it skips any data. */
  if (cinfo->unread_marker == 0) {
    if (! next_marker(cinfo))
      return FALSE;
  }

  if (cinfo->unread_marker ==
      ((int) M_RST0 + cinfo->marker->next_restart_num)) {
    /* Normal case --- swallow the marker and let entropy decoder continue */
    TRACEMS1(cinfo, 3, JTRC_RST, cinfo->marker->next_restart_num);
    cinfo->unread_marker = 0;
  } else {
    /* Uh-oh, the restart markers have been messed up. */
    /* Let the data source manager determine how to resync. */
    if (! (*cinfo->src->resync_to_restart) (cinfo,
					    cinfo->marker->next_restart_num))
      return FALSE;
  }

  /* Update next-restart state */
  cinfo->marker->next_restart_num = (cinfo->marker->next_restart_num + 1) & 7;

  return TRUE;
}


/*
 * This is the default resync_to_restart method for data source managers
 * to use if they don't have any better approach.  Some data source managers
 * may be able to back up, or may have additional knowledge about the data
 * which permits a more intelligent recovery strategy; such managers would
 * presumably supply their own resync method.
 *
 * read_restart_marker calls resync_to_restart if it finds a marker other than
 * the restart marker it was expecting.  (This code is *not* used unless
 * a nonzero restart interval has been declared.)  cinfo->unread_marker is
 * the marker code actually found (might be anything, except 0 or FF).
 * The desired restart marker number (0..7) is passed as a parameter.
 * This routine is supposed to apply whatever error recovery strategy seems
 * appropriate in order to position the input stream to the next data segment.
 * Note that cinfo->unread_marker is treated as a marker appearing before
 * the current data-source input point; usually it should be reset to zero
 * before returning.
 * Returns FALSE if suspension is required.
 *
 * This implementation is substantially constrained by wanting to treat the
 * input as a data stream; this means we can't back up.  Therefore, we have
 * only the following actions to work with:
 *   1. Simply discard the marker and let the entropy decoder resume at next
 *      byte of file.
 *   2. Read forward until we find another marker, discarding intervening
 *      data.  (In theory we could look ahead within the current bufferload,
 *      without having to discard data if we don't find the desired marker.
 *      This idea is not implemented here, in part because it makes behavior
 *      dependent on buffer size and chance buffer-boundary positions.)
 *   3. Leave the marker unread (by failing to zero cinfo->unread_marker).
 *      This will cause the entropy decoder to process an empty data segment,
 *      inserting dummy zeroes, and then we will reprocess the marker.
 *
 * #2 is appropriate if we think the desired marker lies ahead, while #3 is
 * appropriate if the found marker is a future restart marker (indicating
 * that we have missed the desired restart marker, probably because it got
 * corrupted).
 * We apply #2 or #3 if the found marker is a restart marker no more than
 * two counts behind or ahead of the expected one.  We also apply #2 if the
 * found marker is not a legal JPEG marker code (it's certainly bogus data).
 * If the found marker is a restart marker more than 2 counts away, we do #1
 * (too much risk that the marker is erroneous; with luck we will be able to
 * resync at some future point).
 * For any valid non-restart JPEG marker, we apply #3.  This keeps us from
 * overrunning the end of a scan.  An implementation limited to single-scan
 * files might find it better to apply #2 for markers other than EOI, since
 * any other marker would have to be bogus data in that case.
 */

GLOBAL(boolean)
jpeg_resync_to_restart (j_decompress_ptr cinfo, int desired)
{
  int marker = cinfo->unread_marker;
  int action = 1;
  
  /* Always put up a warning. */
//  WARNMS2(cinfo, JWRN_MUST_RESYNC, marker, desired);
  
  /* Outer loop handles repeated decision after scanning forward. */
  for (;;) {
    if (marker < (int) M_SOF0)
      action = 2;		/* invalid marker */
    else if (marker < (int) M_RST0 || marker > (int) M_RST7)
      action = 3;		/* valid non-restart marker */
    else {
      if (marker == ((int) M_RST0 + ((desired+1) & 7)) ||
	  marker == ((int) M_RST0 + ((desired+2) & 7)))
	action = 3;		/* one of the next two expected restarts */
      else if (marker == ((int) M_RST0 + ((desired-1) & 7)) ||
	       marker == ((int) M_RST0 + ((desired-2) & 7)))
	action = 2;		/* a prior restart, so advance */
      else
	action = 1;		/* desired restart or too far away */
    }
    TRACEMS2(cinfo, 4, JTRC_RECOVERY_ACTION, marker, action);
    switch (action) {
    case 1:
      /* Discard marker and let entropy decoder resume processing. */
      cinfo->unread_marker = 0;
      return TRUE;
    case 2:
      /* Scan to the next marker, and repeat the decision loop. */
      if (! next_marker(cinfo))
	return FALSE;
      marker = cinfo->unread_marker;
      break;
    case 3:
      /* Return without advancing past this marker. */
      /* Entropy decoder will be forced to process an empty segment. */
      return TRUE;
    }
  } /* end loop */
}


/*
 * Reset marker processing state to begin a fresh datastream.
 */

METHODDEF(void)
reset_marker_reader (j_decompress_ptr cinfo)
{
  my_marker_ptr marker = (my_marker_ptr) cinfo->marker;

  cinfo->comp_info = NULL;		/* until allocated by get_sof */
  cinfo->input_scan_number = 0;		/* no SOS seen yet */
  cinfo->unread_marker = 0;		/* no pending marker */
  marker->pub.saw_SOI = FALSE;		/* set internal state too */
  marker->pub.saw_SOF = FALSE;
  marker->pub.discarded_bytes = 0;
  marker->cur_marker = NULL;
}


/*
 * Initialize the marker reader module.
 * This is called only once, when the decompression object is created.
 */

GLOBAL(void)
jinit_marker_reader (j_decompress_ptr cinfo)
{
  my_marker_ptr marker;
  int i;

  /* Create subobject in permanent pool */
  marker = (my_marker_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT,
				SIZEOF(my_marker_reader));
  cinfo->marker = (struct jpeg_marker_reader *) marker;
  /* Initialize public method pointers */
  marker->pub.reset_marker_reader = reset_marker_reader;
  marker->pub.read_markers = read_markers;
  marker->pub.read_restart_marker = read_restart_marker;
  /* Initialize COM/APPn processing.
   * By default, we examine and then discard APP0 and APP14,
   * but simply discard COM and all other APPn.
   */
  marker->process_COM = skip_variable;
  marker->length_limit_COM = 0;
  for (i = 0; i < 16; i++) {
    marker->process_APPn[i] = skip_variable;
    marker->length_limit_APPn[i] = 0;
  }
  marker->process_APPn[0] = get_interesting_appn;
  marker->process_APPn[14] = get_interesting_appn;
  /* Reset marker processing state */
  reset_marker_reader(cinfo);
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdmaster.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains master control logic for the JPEG decompressor.
 * These routines are concerned with selecting the modules to be executed
 * and with determining the number of passes and the work to be done in each
 * pass.
 */

/* Private state */

typedef struct {
  struct jpeg_decomp_master pub; /* public fields */
  int pass_number;		/* # of passes completed */
} my_decomp_master;

typedef my_decomp_master * my_master_ptr;



/*
 * Compute output image dimensions and related values.
 * NOTE: this is exported for possible use by application.
 * Hence it mustn't do anything that can't be done twice.
 * Also note that it may be called before the master module is initialized!
 */

void jpeg_calc_output_dimensions(j_decompress_ptr cinfo) {
/* Do computations that are needed before master selection phase */

  /* Hardwire it to "no scaling" */
  cinfo->output_width = cinfo->image_width;
  cinfo->output_height = cinfo->image_height;
  /* jdinput.c has already initialized DCT_scaled_size to DCTSIZE,
   * and has computed unscaled downsampled_width and downsampled_height.
   */

  /* Report number of components in selected colorspace. */
  /* Probably this should be in the color conversion module... */
  cinfo->output_components = cinfo->out_color_components = 3;

    cinfo->rec_outbuf_height = 1;
}


/*
 * Several decompression processes need to range-limit values to the range
 * 0..MAXJSAMPLE; the input value may fall somewhat outside this range
 * due to noise introduced by quantization, roundoff error, etc.  These
 * processes are inner loops and need to be as fast as possible.  On most
 * machines, particularly CPUs with pipelines or instruction prefetch,
 * a (subscript-check-less) C table lookup
 *		x = sample_range_limit[x];
 * is faster than explicit tests
 *		if (x < 0)  x = 0;
 *		else if (x > MAXJSAMPLE)  x = MAXJSAMPLE;
 * These processes all use a common table prepared by the routine below.
 *
 * For most steps we can mathematically guarantee that the initial value
 * of x is within MAXJSAMPLE+1 of the legal range, so a table running from
 * -(MAXJSAMPLE+1) to 2*MAXJSAMPLE+1 is sufficient.  But for the initial
 * limiting step (just after the IDCT), a wildly out-of-range value is 
 * possible if the input data is corrupt.  To avoid any chance of indexing
 * off the end of memory and getting a bad-pointer trap, we perform the
 * post-IDCT limiting thus:
 *		x = range_limit[x & MASK];
 * where MASK is 2 bits wider than legal sample data, ie 10 bits for 8-bit
 * samples.  Under normal circumstances this is more than enough range and
 * a correct output will be generated; with bogus input data the mask will
 * cause wraparound, and we will safely generate a bogus-but-in-range output.
 * For the post-IDCT step, we want to convert the data from signed to unsigned
 * representation by adding CENTERJSAMPLE at the same time that we limit it.
 * So the post-IDCT limiting table ends up looking like this:
 *   CENTERJSAMPLE,CENTERJSAMPLE+1,...,MAXJSAMPLE,
 *   MAXJSAMPLE (repeat 2*(MAXJSAMPLE+1)-CENTERJSAMPLE times),
 *   0          (repeat 2*(MAXJSAMPLE+1)-CENTERJSAMPLE times),
 *   0,1,...,CENTERJSAMPLE-1
 * Negative inputs select values from the upper half of the table after
 * masking.
 *
 * We can save some space by overlapping the start of the post-IDCT table
 * with the simpler range limiting table.  The post-IDCT table begins at
 * sample_range_limit + CENTERJSAMPLE.
 *
 * Note that the table is allocated in near data space on PCs; it's small
 * enough and used often enough to justify this.
 */

LOCAL(void)
prepare_range_limit_table (j_decompress_ptr cinfo)
/* Allocate and fill in the sample_range_limit table */
{
  JSAMPLE * table;
  int i;

  table = (JSAMPLE *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
		(5 * (MAXJSAMPLE+1) + CENTERJSAMPLE) * SIZEOF(JSAMPLE));
  table += (MAXJSAMPLE+1);	/* allow negative subscripts of simple table */
  cinfo->sample_range_limit = table;
  /* First segment of "simple" table: limit[x] = 0 for x < 0 */
  MEMZERO(table - (MAXJSAMPLE+1), (MAXJSAMPLE+1) * SIZEOF(JSAMPLE));
  /* Main part of "simple" table: limit[x] = x */
  for (i = 0; i <= MAXJSAMPLE; i++)
    table[i] = (JSAMPLE) i;
  table += CENTERJSAMPLE;	/* Point to where post-IDCT table starts */
  /* End of simple table, rest of first half of post-IDCT table */
  for (i = CENTERJSAMPLE; i < 2*(MAXJSAMPLE+1); i++)
    table[i] = MAXJSAMPLE;
  /* Second half of post-IDCT table */
  MEMZERO(table + (2 * (MAXJSAMPLE+1)),
	  (2 * (MAXJSAMPLE+1) - CENTERJSAMPLE) * SIZEOF(JSAMPLE));
  MEMCOPY(table + (4 * (MAXJSAMPLE+1) - CENTERJSAMPLE),
	  cinfo->sample_range_limit, CENTERJSAMPLE * SIZEOF(JSAMPLE));
}


/*
 * Master selection of decompression modules.
 * This is done once at jpeg_start_decompress time.  We determine
 * which modules will be used and give them appropriate initialization calls.
 * We also initialize the decompressor input side to begin consuming data.
 *
 * Since jpeg_read_header has finished, we know what is in the SOF
 * and (first) SOS markers.  We also have all the application parameter
 * settings.
 */

int master_selection (j_decompress_ptr cinfo) {

  my_master_ptr master = (my_master_ptr) cinfo->master;
  boolean use_c_buffer;
  long samplesperrow;
  JDIMENSION jd_samplesperrow;

  /* Initialize dimensions and other stuff */
  jpeg_calc_output_dimensions(cinfo);
  prepare_range_limit_table(cinfo);

  /* Width of an output scanline must be representable as JDIMENSION. */
  samplesperrow = (long) cinfo->output_width * (long) cinfo->out_color_components;
  jd_samplesperrow = (JDIMENSION) samplesperrow;
  if ((long) jd_samplesperrow != samplesperrow) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* Initialize my private state */
  master->pass_number = 0;

  /* Post-processing: in particular, color conversion first */
      if( -1==jinit_color_deconverter(cinfo) ) return -1;
      if( -1==jinit_upsampler(cinfo) ) return -1;
    jinit_d_post_controller(cinfo, FALSE);

  /* Inverse DCT */
  jinit_inverse_dct(cinfo);
  /* Entropy decoding: either Huffman or arithmetic coding. */
  if (cinfo->arith_code) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
  } else {
    if (cinfo->progressive_mode) {
      jinit_phuff_decoder(cinfo);
    } else
      jinit_huff_decoder(cinfo);
  }

  /* Initialize principal buffer controllers. */
  use_c_buffer = cinfo->inputctl->has_multiple_scans || cinfo->buffered_image;
  jinit_d_coef_controller(cinfo, use_c_buffer);

    if( -1==jinit_d_main_controller(cinfo, FALSE /* never need full buffer here */) ) return -1;

  /* We can now tell the memory manager to allocate virtual arrays. */
  (*cinfo->mem->realize_virt_arrays) ((j_common_ptr) cinfo);

  /* Initialize input side of decompressor to consume first scan. */
  if( -1==(*cinfo->inputctl->start_input_pass) (cinfo) ) return -1;
	return 0;
}


/*
 * Per-pass setup.
 * This is called at the beginning of each output pass.  We determine which
 * modules will be active during this pass and give them appropriate
 * start_pass calls.  We also set is_dummy_pass to indicate whether this
 * is a "real" output pass or a dummy pass for color quantization.
 * (In the latter case, jdapistd.c will crank the pass to completion.)
 */

int prepare_for_output_pass (j_decompress_ptr cinfo) {

	my_master_ptr master = (my_master_ptr) cinfo->master;

	if (master->pub.is_dummy_pass) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	} else {
		if( -1==(*cinfo->idct->start_pass) (cinfo) ) return -1;
		(*cinfo->coef->start_output_pass) (cinfo);

		if( -1==(*cinfo->cconvert->start_pass) (cinfo) ) return -1;
		if( -1==(*cinfo->upsample->start_pass) (cinfo) ) return -1;
		if( -1==(*cinfo->post->start_pass) (cinfo, (master->pub.is_dummy_pass ? JBUF_SAVE_AND_PASS : JBUF_PASS_THRU)) ) return -1;
		if( -1==(*cinfo->main->start_pass) (cinfo, JBUF_PASS_THRU) ) return -1;
	}
	return 0;
}


/*
 * Finish up at end of an output pass.
 */

METHODDEF(void)
finish_output_pass (j_decompress_ptr cinfo)
{
  my_master_ptr master = (my_master_ptr) cinfo->master;

  master->pass_number++;
}



/*
 * Initialize master decompression control and select active modules.
 * This is performed at the start of jpeg_start_decompress.
 */

int jinit_master_decompress (j_decompress_ptr cinfo) {

  my_master_ptr master;

  master = (my_master_ptr)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  SIZEOF(my_decomp_master));
  cinfo->master = (struct jpeg_decomp_master *) master;
  master->pub.prepare_for_output_pass = prepare_for_output_pass;
  master->pub.finish_output_pass = finish_output_pass;

  master->pub.is_dummy_pass = FALSE;

  return master_selection(cinfo);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdmerge.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains code for merged upsampling/color conversion.
 *
 * This file combines functions from jdsample.c and jdcolor.c;
 * read those files first to understand what's going on.
 *
 * When the chroma components are to be upsampled by simple replication
 * (ie, box filtering), we can save some work in color conversion by
 * calculating all the output pixels corresponding to a pair of chroma
 * samples at one time.  In the conversion equations
 *	R = Y           + K1 * Cr
 *	G = Y + K2 * Cb + K3 * Cr
 *	B = Y + K4 * Cb
 * only the Y term varies among the group of pixels corresponding to a pair
 * of chroma samples, so the rest of the terms can be calculated just once.
 * At typical sampling ratios, this eliminates half or three-quarters of the
 * multiplications needed for color conversion.
 *
 * This file currently provides implementations for the following cases:
 *	YCbCr => RGB color conversion only.
 *	Sampling ratios of 2h1v or 2h2v.
 *	No scaling needed at upsample time.
 *	Corner-aligned (non-CCIR601) sampling alignment.
 * Other special cases could be added, but in most applications these are
 * the only common cases.  (For uncommon cases we fall back on the more
 * general code in jdsample.c and jdcolor.c.)
 */

#ifdef UPSAMPLE_MERGING_SUPPORTED


/* Private subobject */

typedef struct {
  struct jpeg_upsampler pub;	/* public fields */

  /* Pointer to routine to do actual upsampling/conversion of one row group */
  JMETHOD(void, upmethod, (j_decompress_ptr cinfo,
			   JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr,
			   JSAMPARRAY output_buf));

  /* Private state for YCC->RGB conversion */
  int * Cr_r_tab;		/* => table for Cr to R conversion */
  int * Cb_b_tab;		/* => table for Cb to B conversion */
  INT32 * Cr_g_tab;		/* => table for Cr to G conversion */
  INT32 * Cb_g_tab;		/* => table for Cb to G conversion */

  /* For 2:1 vertical sampling, we produce two output rows at a time.
   * We need a "spare" row buffer to hold the second output row if the
   * application provides just a one-row buffer; we also use the spare
   * to discard the dummy last row if the image height is odd.
   */
  JSAMPROW spare_row;
  boolean spare_full;		/* T if spare buffer is occupied */

  JDIMENSION out_row_width;	/* samples per output row */
  JDIMENSION rows_to_go;	/* counts rows remaining in image */
} mmy_upsampler;

typedef mmy_upsampler * mmy_upsample_ptr;

/*
 * Initialize tables for YCC->RGB colorspace conversion.
 * This is taken directly from jdcolor.c; see that file for more info.
 */

LOCAL(void)
build_ycc_rgb_table (j_decompress_ptr cinfo)
{
  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;
  int i;
  INT32 x;
  SHIFT_TEMPS

  upsample->Cr_r_tab = (int *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(int));
  upsample->Cb_b_tab = (int *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(int));
  upsample->Cr_g_tab = (INT32 *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(INT32));
  upsample->Cb_g_tab = (INT32 *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				(MAXJSAMPLE+1) * SIZEOF(INT32));

  for (i = 0, x = -CENTERJSAMPLE; i <= MAXJSAMPLE; i++, x++) {
    /* i is the actual input pixel value, in the range 0..MAXJSAMPLE */
    /* The Cb or Cr value we are thinking of is x = i - CENTERJSAMPLE */
    /* Cr=>R value is nearest int to 1.40200 * x */
    upsample->Cr_r_tab[i] = (int)
		    RIGHT_SHIFT(MERGEFIX(1.40200) * x + ONE_HALF, SCALEBITS);
    /* Cb=>B value is nearest int to 1.77200 * x */
    upsample->Cb_b_tab[i] = (int)
		    RIGHT_SHIFT(MERGEFIX(1.77200) * x + ONE_HALF, SCALEBITS);
    /* Cr=>G value is scaled-up -0.71414 * x */
    upsample->Cr_g_tab[i] = (- MERGEFIX(0.71414)) * x;
    /* Cb=>G value is scaled-up -0.34414 * x */
    /* We also add in ONE_HALF so that need not do it in inner loop */
    upsample->Cb_g_tab[i] = (- MERGEFIX(0.34414)) * x + ONE_HALF;
  }
}


/*
 * Initialize for an upsampling pass.
 */

int start_pass_merged_upsample (j_decompress_ptr cinfo) {

  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;

  /* Mark the spare buffer empty */
  upsample->spare_full = FALSE;
  /* Initialize total-height counter for detecting bottom of image */
  upsample->rows_to_go = cinfo->output_height;
	return 0;
}


/*
 * Control routine to do upsampling (and color conversion).
 *
 * The control routine just handles the row buffering considerations.
 */

METHODDEF(void)
merged_2v_upsample (j_decompress_ptr cinfo,
		    JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr,
		    JDIMENSION in_row_groups_avail,
		    JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
		    JDIMENSION out_rows_avail)
/* 2:1 vertical sampling case: may need a spare row. */
{
  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;
  JSAMPROW work_ptrs[2];
  JDIMENSION num_rows;		/* number of rows returned to caller */

  if (upsample->spare_full) {
    /* If we have a spare row saved from a previous cycle, just return it. */
    jcopy_sample_rows(& upsample->spare_row, 0, output_buf + *out_row_ctr, 0,
		      1, upsample->out_row_width);
    num_rows = 1;
    upsample->spare_full = FALSE;
  } else {
    /* Figure number of rows to return to caller. */
    num_rows = 2;
    /* Not more than the distance to the end of the image. */
    if (num_rows > upsample->rows_to_go)
      num_rows = upsample->rows_to_go;
    /* And not more than what the client can accept: */
    out_rows_avail -= *out_row_ctr;
    if (num_rows > out_rows_avail)
      num_rows = out_rows_avail;
    /* Create output pointer array for upsampler. */
    work_ptrs[0] = output_buf[*out_row_ctr];
    if (num_rows > 1) {
      work_ptrs[1] = output_buf[*out_row_ctr + 1];
    } else {
      work_ptrs[1] = upsample->spare_row;
      upsample->spare_full = TRUE;
    }
    /* Now do the upsampling. */
    (*upsample->upmethod) (cinfo, input_buf, *in_row_group_ctr, work_ptrs);
  }

  /* Adjust counts */
  *out_row_ctr += num_rows;
  upsample->rows_to_go -= num_rows;
  /* When the buffer is emptied, declare this input row group consumed */
  if (! upsample->spare_full)
    (*in_row_group_ctr)++;
}


METHODDEF(void)
merged_1v_upsample (j_decompress_ptr cinfo,
		    JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr,
		    JDIMENSION in_row_groups_avail,
		    JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
		    JDIMENSION out_rows_avail)
/* 1:1 vertical sampling case: much easier, never need a spare row. */
{
  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;

  /* Just do the upsampling. */
  (*upsample->upmethod) (cinfo, input_buf, *in_row_group_ctr,
			 output_buf + *out_row_ctr);
  /* Adjust counts */
  (*out_row_ctr)++;
  (*in_row_group_ctr)++;
}


/*
 * These are the routines invoked by the control routines to do
 * the actual upsampling/conversion.  One row group is processed per call.
 *
 * Note: since we may be writing directly into application-supplied buffers,
 * we have to be honest about the output width; we can't assume the buffer
 * has been rounded up to an even width.
 */


/*
 * Upsample and color convert for the case of 2:1 horizontal and 1:1 vertical.
 */

METHODDEF(void)
h2v1_merged_upsample (j_decompress_ptr cinfo,
		      JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr,
		      JSAMPARRAY output_buf)
{
  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;
  register int y, cred, cgreen, cblue;
  int cb, cr;
  register JSAMPROW outptr;
  JSAMPROW inptr0, inptr1, inptr2;
  JDIMENSION col;
  /* copy these pointers into registers if possible */
  register JSAMPLE * range_limit = cinfo->sample_range_limit;
  int * Crrtab = upsample->Cr_r_tab;
  int * Cbbtab = upsample->Cb_b_tab;
  INT32 * Crgtab = upsample->Cr_g_tab;
  INT32 * Cbgtab = upsample->Cb_g_tab;
  SHIFT_TEMPS

  inptr0 = input_buf[0][in_row_group_ctr];
  inptr1 = input_buf[1][in_row_group_ctr];
  inptr2 = input_buf[2][in_row_group_ctr];
  outptr = output_buf[0];
  /* Loop for each pair of output pixels */
  for (col = cinfo->output_width >> 1; col > 0; col--) {
    /* Do the chroma part of the calculation */
    cb = GETJSAMPLE(*inptr1++);
    cr = GETJSAMPLE(*inptr2++);
    cred = Crrtab[cr];
    cgreen = (int) RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr], SCALEBITS);
    cblue = Cbbtab[cb];
    /* Fetch 2 Y values and emit 2 pixels */
    y  = GETJSAMPLE(*inptr0++);
    outptr[RGB_RED] =   range_limit[y + cred];
    outptr[RGB_GREEN] = range_limit[y + cgreen];
    outptr[RGB_BLUE] =  range_limit[y + cblue];
    outptr += RGB_PIXELSIZE;
    y  = GETJSAMPLE(*inptr0++);
    outptr[RGB_RED] =   range_limit[y + cred];
    outptr[RGB_GREEN] = range_limit[y + cgreen];
    outptr[RGB_BLUE] =  range_limit[y + cblue];
    outptr += RGB_PIXELSIZE;
  }
  /* If image width is odd, do the last output column separately */
  if (cinfo->output_width & 1) {
    cb = GETJSAMPLE(*inptr1);
    cr = GETJSAMPLE(*inptr2);
    cred = Crrtab[cr];
    cgreen = (int) RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr], SCALEBITS);
    cblue = Cbbtab[cb];
    y  = GETJSAMPLE(*inptr0);
    outptr[RGB_RED] =   range_limit[y + cred];
    outptr[RGB_GREEN] = range_limit[y + cgreen];
    outptr[RGB_BLUE] =  range_limit[y + cblue];
  }
}


/*
 * Upsample and color convert for the case of 2:1 horizontal and 2:1 vertical.
 */

METHODDEF(void)
h2v2_merged_upsample (j_decompress_ptr cinfo,
		      JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr,
		      JSAMPARRAY output_buf)
{
  mmy_upsample_ptr upsample = (mmy_upsample_ptr) cinfo->upsample;
  register int y, cred, cgreen, cblue;
  int cb, cr;
  register JSAMPROW outptr0, outptr1;
  JSAMPROW inptr00, inptr01, inptr1, inptr2;
  JDIMENSION col;
  /* copy these pointers into registers if possible */
  register JSAMPLE * range_limit = cinfo->sample_range_limit;
  int * Crrtab = upsample->Cr_r_tab;
  int * Cbbtab = upsample->Cb_b_tab;
  INT32 * Crgtab = upsample->Cr_g_tab;
  INT32 * Cbgtab = upsample->Cb_g_tab;
  SHIFT_TEMPS

  inptr00 = input_buf[0][in_row_group_ctr*2];
  inptr01 = input_buf[0][in_row_group_ctr*2 + 1];
  inptr1 = input_buf[1][in_row_group_ctr];
  inptr2 = input_buf[2][in_row_group_ctr];
  outptr0 = output_buf[0];
  outptr1 = output_buf[1];
  /* Loop for each group of output pixels */
  for (col = cinfo->output_width >> 1; col > 0; col--) {
    /* Do the chroma part of the calculation */
    cb = GETJSAMPLE(*inptr1++);
    cr = GETJSAMPLE(*inptr2++);
    cred = Crrtab[cr];
    cgreen = (int) RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr], SCALEBITS);
    cblue = Cbbtab[cb];
    /* Fetch 4 Y values and emit 4 pixels */
    y  = GETJSAMPLE(*inptr00++);
    outptr0[RGB_RED] =   range_limit[y + cred];
    outptr0[RGB_GREEN] = range_limit[y + cgreen];
    outptr0[RGB_BLUE] =  range_limit[y + cblue];
    outptr0 += RGB_PIXELSIZE;
    y  = GETJSAMPLE(*inptr00++);
    outptr0[RGB_RED] =   range_limit[y + cred];
    outptr0[RGB_GREEN] = range_limit[y + cgreen];
    outptr0[RGB_BLUE] =  range_limit[y + cblue];
    outptr0 += RGB_PIXELSIZE;
    y  = GETJSAMPLE(*inptr01++);
    outptr1[RGB_RED] =   range_limit[y + cred];
    outptr1[RGB_GREEN] = range_limit[y + cgreen];
    outptr1[RGB_BLUE] =  range_limit[y + cblue];
    outptr1 += RGB_PIXELSIZE;
    y  = GETJSAMPLE(*inptr01++);
    outptr1[RGB_RED] =   range_limit[y + cred];
    outptr1[RGB_GREEN] = range_limit[y + cgreen];
    outptr1[RGB_BLUE] =  range_limit[y + cblue];
    outptr1 += RGB_PIXELSIZE;
  }
  /* If image width is odd, do the last output column separately */
  if (cinfo->output_width & 1) {
    cb = GETJSAMPLE(*inptr1);
    cr = GETJSAMPLE(*inptr2);
    cred = Crrtab[cr];
    cgreen = (int) RIGHT_SHIFT(Cbgtab[cb] + Crgtab[cr], SCALEBITS);
    cblue = Cbbtab[cb];
    y  = GETJSAMPLE(*inptr00);
    outptr0[RGB_RED] =   range_limit[y + cred];
    outptr0[RGB_GREEN] = range_limit[y + cgreen];
    outptr0[RGB_BLUE] =  range_limit[y + cblue];
    y  = GETJSAMPLE(*inptr01);
    outptr1[RGB_RED] =   range_limit[y + cred];
    outptr1[RGB_GREEN] = range_limit[y + cgreen];
    outptr1[RGB_BLUE] =  range_limit[y + cblue];
  }
}


/*
 * Module initialization routine for merged upsampling/color conversion.
 *
 * NB: this is called under the conditions determined by use_merged_upsample()
 * in jdmaster.c.  That routine MUST correspond to the actual capabilities
 * of this module; no safety checks are made here.
 */

GLOBAL(void)
jinit_merged_upsampler (j_decompress_ptr cinfo)
{
  mmy_upsample_ptr upsample;

  upsample = (mmy_upsample_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(mmy_upsampler));
  cinfo->upsample = (struct jpeg_upsampler *) upsample;
  upsample->pub.start_pass = start_pass_merged_upsample;
  upsample->pub.need_context_rows = FALSE;

  upsample->out_row_width = cinfo->output_width * cinfo->out_color_components;

  if (cinfo->max_v_samp_factor == 2) {
    upsample->pub.upsample = merged_2v_upsample;
    upsample->upmethod = h2v2_merged_upsample;
    /* Allocate a spare row buffer */
    upsample->spare_row = (JSAMPROW)
      (*cinfo->mem->alloc_large) ((j_common_ptr) cinfo, JPOOL_IMAGE,
		(size_t) (upsample->out_row_width * SIZEOF(JSAMPLE)));
  } else {
    upsample->pub.upsample = merged_1v_upsample;
    upsample->upmethod = h2v1_merged_upsample;
    /* No spare row needed */
    upsample->spare_row = NULL;
  }

  build_ycc_rgb_table(cinfo);
}

#endif /* UPSAMPLE_MERGING_SUPPORTED */

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdphuff.c
 *
 * Copyright (C) 1995-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains Huffman entropy decoding routines for progressive JPEG.
 *
 * Much of the complexity here has to do with supporting input suspension.
 * If the data source module demands suspension, we want to be able to back
 * up to the start of the current MCU.  To do this, we copy state variables
 * into local working storage, and update them back to the permanent
 * storage only upon successful completion of an MCU.
 */

#ifdef D_PROGRESSIVE_SUPPORTED

/*
 * Expanded entropy decoder object for progressive Huffman decoding.
 *
 * The savable_state subrecord contains fields that change within an MCU,
 * but must not be updated permanently until we complete the MCU.
 */

typedef struct {
  unsigned int EOBRUN;			/* remaining EOBs in EOBRUN */
  int last_dc_val[MAX_COMPS_IN_SCAN];	/* last DC coef for each component */
} savable_state;

/* This macro is to work around compilers with missing or broken
 * structure assignment.  You'll need to fix this code if you have
 * such a compiler and you change MAX_COMPS_IN_SCAN.
 */

#ifndef NO_STRUCT_ASSIGN
#define ASSIGN_STATE(dest,src)  ((dest) = (src))
#else
#if MAX_COMPS_IN_SCAN == 4
#define ASSIGN_STATE(dest,src)  \
	((dest).EOBRUN = (src).EOBRUN, \
	 (dest).last_dc_val[0] = (src).last_dc_val[0], \
	 (dest).last_dc_val[1] = (src).last_dc_val[1], \
	 (dest).last_dc_val[2] = (src).last_dc_val[2], \
	 (dest).last_dc_val[3] = (src).last_dc_val[3])
#endif
#endif


typedef struct {
  struct jpeg_entropy_decoder pub; /* public fields */

  /* These fields are loaded into local variables at start of each MCU.
   * In case of suspension, we exit WITHOUT updating them.
   */
  bitread_perm_state bitstate;	/* Bit buffer at start of MCU */
  savable_state saved;		/* Other state at start of MCU */

  /* These fields are NOT loaded into local working state. */
  unsigned int restarts_to_go;	/* MCUs left in this restart interval */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  d_derived_tbl * derived_tbls[NUM_HUFF_TBLS];

  d_derived_tbl * ac_derived_tbl; /* active table during an AC scan */
} phuff_entropy_decoder;

typedef phuff_entropy_decoder * phuff_entropy_ptr;

/* Forward declarations */
int decode_mcu_DC_first JPP((j_decompress_ptr cinfo,
					    JBLOCKROW *MCU_data));
int decode_mcu_AC_first JPP((j_decompress_ptr cinfo,
					    JBLOCKROW *MCU_data));
int decode_mcu_DC_refine JPP((j_decompress_ptr cinfo,
					     JBLOCKROW *MCU_data));
int decode_mcu_AC_refine JPP((j_decompress_ptr cinfo,
					     JBLOCKROW *MCU_data));


/*
 * Initialize for a Huffman-compressed scan.
 */

int start_pass_phuff_decoder (j_decompress_ptr cinfo) {

  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  boolean is_DC_band, bad;
  int ci, coefi, tbl;
  int *coef_bit_ptr;
  jpeg_component_info * compptr;

  is_DC_band = (cinfo->Ss == 0);

  /* Validate scan parameters */
  bad = FALSE;
  if (is_DC_band) {
    if (cinfo->Se != 0)
      bad = TRUE;
  } else {
    /* need not check Ss/Se < 0 since they came from unsigned bytes */
    if (cinfo->Ss > cinfo->Se || cinfo->Se >= DCTSIZE2)
      bad = TRUE;
    /* AC scans may have only one component */
    if (cinfo->comps_in_scan != 1)
      bad = TRUE;
  }
  if (cinfo->Ah != 0) {
    /* Successive approximation refinement scan: must have Al = Ah-1. */
    if (cinfo->Al != cinfo->Ah-1)
      bad = TRUE;
  }
  if (cinfo->Al > 13)		/* need not check for < 0 */
    bad = TRUE;
  /* Arguably the maximum Al value should be less than 13 for 8-bit precision,
   * but the spec doesn't say so, and we try to be liberal about what we
   * accept.  Note: large Al values could result in out-of-range DC
   * coefficients during early scans, leading to bizarre displays due to
   * overflows in the IDCT math.  But we won't crash.
   */
  if (bad) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
  /* Update progression status, and verify that scan order is legal.
   * Note that inter-scan inconsistencies are treated as warnings
   * not fatal errors ... not clear if this is right way to behave.
   */
  for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
    int cindex = cinfo->cur_comp_info[ci]->component_index;
    coef_bit_ptr = & cinfo->coef_bits[cindex][0];
    if (!is_DC_band && coef_bit_ptr[0] < 0) {/* AC without prior DC scan */
//      WARNMS2(cinfo, JWRN_BOGUS_PROGRESSION, cindex, 0);
	}
    for (coefi = cinfo->Ss; coefi <= cinfo->Se; coefi++) {
      int expected = (coef_bit_ptr[coefi] < 0) ? 0 : coef_bit_ptr[coefi];
      if (cinfo->Ah != expected) {
//	WARNMS2(cinfo, JWRN_BOGUS_PROGRESSION, cindex, coefi);
	}
      coef_bit_ptr[coefi] = cinfo->Al;
    }
  }

  /* Select MCU decoding routine */
  if (cinfo->Ah == 0) {
    if (is_DC_band)
      entropy->pub.decode_mcu = decode_mcu_DC_first;
    else
      entropy->pub.decode_mcu = decode_mcu_AC_first;
  } else {
    if (is_DC_band)
      entropy->pub.decode_mcu = decode_mcu_DC_refine;
    else
      entropy->pub.decode_mcu = decode_mcu_AC_refine;
  }

  for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
    compptr = cinfo->cur_comp_info[ci];
    /* Make sure requested tables are present, and compute derived tables.
     * We may build same derived table more than once, but it's not expensive.
     */
    if (is_DC_band) {
      if (cinfo->Ah == 0) {	/* DC refinement needs no table */
	tbl = compptr->dc_tbl_no;
	jpeg_make_d_derived_tbl(cinfo, TRUE, tbl,
				& entropy->derived_tbls[tbl]);
      }
    } else {
      tbl = compptr->ac_tbl_no;
      jpeg_make_d_derived_tbl(cinfo, FALSE, tbl,
			      & entropy->derived_tbls[tbl]);
      /* remember the single active table */
      entropy->ac_derived_tbl = entropy->derived_tbls[tbl];
    }
    /* Initialize DC predictions to 0 */
    entropy->saved.last_dc_val[ci] = 0;
  }

  /* Initialize bitread state variables */
  entropy->bitstate.bits_left = 0;
  entropy->bitstate.get_buffer = 0; /* unnecessary, but keeps Purify quiet */
  entropy->pub.insufficient_data = FALSE;

  /* Initialize private state variables */
  entropy->saved.EOBRUN = 0;

  /* Initialize restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;
	return 0;
}


/*
 * Check for a restart marker & resynchronize decoder.
 * Returns FALSE if must suspend.
 */

LOCAL(boolean)
process_restart (j_decompress_ptr cinfo)
{
  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  int ci;

  /* Throw away any unused bits remaining in bit buffer; */
  /* include any full bytes in next_marker's count of discarded bytes */
  cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
  entropy->bitstate.bits_left = 0;

  /* Advance past the RSTn marker */
  if (! (*cinfo->marker->read_restart_marker) (cinfo))  return FALSE;

  /* Re-initialize DC predictions to 0 */
  for (ci = 0; ci < cinfo->comps_in_scan; ci++)
    entropy->saved.last_dc_val[ci] = 0;
  /* Re-init EOB run count, too */
  entropy->saved.EOBRUN = 0;

  /* Reset restart counter */
  entropy->restarts_to_go = cinfo->restart_interval;

  /* Reset out-of-data flag, unless read_restart_marker left us smack up
   * against a marker.  In that case we will end up treating the next data
   * segment as empty, and we can avoid producing bogus output pixels by
   * leaving the flag set.
   */
  if (cinfo->unread_marker == 0)
    entropy->pub.insufficient_data = FALSE;

  return TRUE;
}


/*
 * Huffman MCU decoding.
 * Each of these routines decodes and returns one MCU's worth of
 * Huffman-compressed coefficients. 
 * The coefficients are reordered from zigzag order into natural array order,
 * but are not dequantized.
 *
 * The i'th block of the MCU is stored into the block pointed to by
 * MCU_data[i].  WE ASSUME THIS AREA IS INITIALLY ZEROED BY THE CALLER.
 *
 * We return FALSE if data source requested suspension.  In that case no
 * changes have been made to permanent state.  (Exception: some output
 * coefficients may already have been assigned.  This is harmless for
 * spectral selection, since we'll just re-assign them on the next call.
 * Successive approximation AC refinement has to be more careful, however.)
 */

/*
 * MCU decoding for DC initial scan (either spectral selection,
 * or first pass of successive approximation).
 */

int decode_mcu_DC_first (j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{   
  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  int Al = cinfo->Al;
  register int s, r;
  int blkn, ci;
  JBLOCKROW block;
  BITREAD_STATE_VARS;
  savable_state state;
  d_derived_tbl * tbl;
  jpeg_component_info * compptr;

  /* Process restart marker if needed; may have to suspend */
  if (cinfo->restart_interval) {
    if (entropy->restarts_to_go == 0)
      if (! process_restart(cinfo))
	return FALSE;
  }

  /* If we've run out of data, just leave the MCU set to zeroes.
   * This way, we return uniform gray for the remainder of the segment.
   */
  if (! entropy->pub.insufficient_data) {

    /* Load up working state */
    BITREAD_LOAD_STATE(cinfo,entropy->bitstate);
    ASSIGN_STATE(state, entropy->saved);

    /* Outer loop handles each block in the MCU */

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
      block = MCU_data[blkn];
      ci = cinfo->MCU_membership[blkn];
      compptr = cinfo->cur_comp_info[ci];
      tbl = entropy->derived_tbls[compptr->dc_tbl_no];

      /* Decode a single block's worth of coefficients */

      /* Section F.2.2.1: decode the DC coefficient difference */
      HUFF_DECODE(s, br_state, tbl, return FALSE, label1);
      if (s) {
	CHECK_BIT_BUFFER(br_state, s, return FALSE);
	r = GET_BITS(s);
	s = HUFF_EXTEND(r, s);
      }

      /* Convert DC difference to actual value, update last_dc_val */
      s += state.last_dc_val[ci];
      state.last_dc_val[ci] = s;
      /* Scale and output the coefficient (assumes jpeg_natural_order[0]=0) */
      (*block)[0] = (JCOEF) (s << Al);
    }

    /* Completed MCU, so update state */
    BITREAD_SAVE_STATE(cinfo,entropy->bitstate);
    ASSIGN_STATE(entropy->saved, state);
  }

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;
}


/*
 * MCU decoding for AC initial scan (either spectral selection,
 * or first pass of successive approximation).
 */

int decode_mcu_AC_first (j_decompress_ptr cinfo, JBLOCKROW *MCU_data) {

  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  int Se = cinfo->Se;
  int Al = cinfo->Al;
  register int s, k, r;
  unsigned int EOBRUN;
  JBLOCKROW block;
  BITREAD_STATE_VARS;
  d_derived_tbl * tbl;

  /* Process restart marker if needed; may have to suspend */
  if (cinfo->restart_interval) {
    if (entropy->restarts_to_go == 0)
      if (! process_restart(cinfo))
	return FALSE;
  }

  /* If we've run out of data, just leave the MCU set to zeroes.
   * This way, we return uniform gray for the remainder of the segment.
   */
  if (! entropy->pub.insufficient_data) {

    /* Load up working state.
     * We can avoid loading/saving bitread state if in an EOB run.
     */
    EOBRUN = entropy->saved.EOBRUN;	/* only part of saved state we need */

    /* There is always only one block per MCU */

    if (EOBRUN > 0)		/* if it's a band of zeroes... */
      EOBRUN--;			/* ...process it now (we do nothing) */
    else {
      BITREAD_LOAD_STATE(cinfo,entropy->bitstate);
      block = MCU_data[0];
      tbl = entropy->ac_derived_tbl;

      for (k = cinfo->Ss; k <= Se; k++) {
	HUFF_DECODE(s, br_state, tbl, return FALSE, label2);
	r = s >> 4;
	s &= 15;
	if (s) {
	  k += r;
	  CHECK_BIT_BUFFER(br_state, s, return FALSE);
	  r = GET_BITS(s);
	  s = HUFF_EXTEND(r, s);
	  /* Scale and output coefficient in natural (dezigzagged) order */
	  (*block)[jpeg_natural_order[k]] = (JCOEF) (s << Al);
	} else {
	  if (r == 15) {	/* ZRL */
	    k += 15;		/* skip 15 zeroes in band */
	  } else {		/* EOBr, run length is 2^r + appended bits */
	    EOBRUN = 1 << r;
	    if (r) {		/* EOBr, r > 0 */
	      CHECK_BIT_BUFFER(br_state, r, return FALSE);
	      r = GET_BITS(r);
	      EOBRUN += r;
	    }
	    EOBRUN--;		/* this band is processed at this moment */
	    break;		/* force end-of-band */
	  }
	}
      }

      BITREAD_SAVE_STATE(cinfo,entropy->bitstate);
    }

    /* Completed MCU, so update state */
    entropy->saved.EOBRUN = EOBRUN;	/* only part of saved state we need */
  }

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;
}


/*
 * MCU decoding for DC successive approximation refinement scan.
 * Note: we assume such scans can be multi-component, although the spec
 * is not very clear on the point.
 */

int decode_mcu_DC_refine (j_decompress_ptr cinfo, JBLOCKROW *MCU_data) {

  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  int p1 = 1 << cinfo->Al;	/* 1 in the bit position being coded */
  int blkn;
  JBLOCKROW block;
  BITREAD_STATE_VARS;

  /* Process restart marker if needed; may have to suspend */
  if (cinfo->restart_interval) {
    if (entropy->restarts_to_go == 0)
      if (! process_restart(cinfo))
	return FALSE;
  }

  /* Not worth the cycles to check insufficient_data here,
   * since we will not change the data anyway if we read zeroes.
   */

  /* Load up working state */
  BITREAD_LOAD_STATE(cinfo,entropy->bitstate);

  /* Outer loop handles each block in the MCU */

  for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
    block = MCU_data[blkn];

    /* Encoded data is simply the next bit of the two's-complement DC value */
    CHECK_BIT_BUFFER(br_state, 1, return FALSE);
    if (GET_BITS(1))
      (*block)[0] |= p1;
    /* Note: since we use |=, repeating the assignment later is safe */
  }

  /* Completed MCU, so update state */
  BITREAD_SAVE_STATE(cinfo,entropy->bitstate);

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;
}


/*
 * MCU decoding for AC successive approximation refinement scan.
 */

int decode_mcu_AC_refine (j_decompress_ptr cinfo, JBLOCKROW *MCU_data) {   

  phuff_entropy_ptr entropy = (phuff_entropy_ptr) cinfo->entropy;
  int Se = cinfo->Se;
  int p1 = 1 << cinfo->Al;	/* 1 in the bit position being coded */
  int m1 = (-1) << cinfo->Al;	/* -1 in the bit position being coded */
  register int s, k, r;
  unsigned int EOBRUN;
  JBLOCKROW block;
  JCOEFPTR thiscoef;
  BITREAD_STATE_VARS;
  d_derived_tbl * tbl;
  int num_newnz;
  int newnz_pos[DCTSIZE2];

  /* Process restart marker if needed; may have to suspend */
  if (cinfo->restart_interval) {
    if (entropy->restarts_to_go == 0)
      if (! process_restart(cinfo))
	return FALSE;
  }

  /* If we've run out of data, don't modify the MCU.
   */
  if (! entropy->pub.insufficient_data) {

    /* Load up working state */
    BITREAD_LOAD_STATE(cinfo,entropy->bitstate);
    EOBRUN = entropy->saved.EOBRUN; /* only part of saved state we need */

    /* There is always only one block per MCU */
    block = MCU_data[0];
    tbl = entropy->ac_derived_tbl;

    /* If we are forced to suspend, we must undo the assignments to any newly
     * nonzero coefficients in the block, because otherwise we'd get confused
     * next time about which coefficients were already nonzero.
     * But we need not undo addition of bits to already-nonzero coefficients;
     * instead, we can test the current bit to see if we already did it.
     */
    num_newnz = 0;

    /* initialize coefficient loop counter to start of band */
    k = cinfo->Ss;

    if (EOBRUN == 0) {
      for (; k <= Se; k++) {
	HUFF_DECODE(s, br_state, tbl, goto undoit, label3);
	r = s >> 4;
	s &= 15;
	if (s) {
	  if (s != 1) {		/* size of new coef should always be 1 */
//	    WARNMS(cinfo, JWRN_HUFF_BAD_CODE);
	}
	  CHECK_BIT_BUFFER(br_state, 1, goto undoit);
	  if (GET_BITS(1))
	    s = p1;		/* newly nonzero coef is positive */
	  else
	    s = m1;		/* newly nonzero coef is negative */
	} else {
	  if (r != 15) {
	    EOBRUN = 1 << r;	/* EOBr, run length is 2^r + appended bits */
	    if (r) {
	      CHECK_BIT_BUFFER(br_state, r, goto undoit);
	      r = GET_BITS(r);
	      EOBRUN += r;
	    }
	    break;		/* rest of block is handled by EOB logic */
	  }
	  /* note s = 0 for processing ZRL */
	}
	/* Advance over already-nonzero coefs and r still-zero coefs,
	 * appending correction bits to the nonzeroes.  A correction bit is 1
	 * if the absolute value of the coefficient must be increased.
	 */
	do {
	  thiscoef = *block + jpeg_natural_order[k];
	  if (*thiscoef != 0) {
	    CHECK_BIT_BUFFER(br_state, 1, goto undoit);
	    if (GET_BITS(1)) {
	      if ((*thiscoef & p1) == 0) { /* do nothing if already set it */
		if (*thiscoef >= 0)
		  *thiscoef += p1;
		else
		  *thiscoef += m1;
	      }
	    }
	  } else {
	    if (--r < 0)
	      break;		/* reached target zero coefficient */
	  }
	  k++;
	} while (k <= Se);
	if (s) {
	  int pos = jpeg_natural_order[k];
	  /* Output newly nonzero coefficient */
	  (*block)[pos] = (JCOEF) s;
	  /* Remember its position in case we have to suspend */
	  newnz_pos[num_newnz++] = pos;
	}
      }
    }

    if (EOBRUN > 0) {
      /* Scan any remaining coefficient positions after the end-of-band
       * (the last newly nonzero coefficient, if any).  Append a correction
       * bit to each already-nonzero coefficient.  A correction bit is 1
       * if the absolute value of the coefficient must be increased.
       */
      for (; k <= Se; k++) {
	thiscoef = *block + jpeg_natural_order[k];
	if (*thiscoef != 0) {
	  CHECK_BIT_BUFFER(br_state, 1, goto undoit);
	  if (GET_BITS(1)) {
	    if ((*thiscoef & p1) == 0) { /* do nothing if already changed it */
	      if (*thiscoef >= 0)
		*thiscoef += p1;
	      else
		*thiscoef += m1;
	    }
	  }
	}
      }
      /* Count one block completed in EOB run */
      EOBRUN--;
    }

    /* Completed MCU, so update state */
    BITREAD_SAVE_STATE(cinfo,entropy->bitstate);
    entropy->saved.EOBRUN = EOBRUN; /* only part of saved state we need */
  }

  /* Account for restart interval (no-op if not using restarts) */
  entropy->restarts_to_go--;

  return TRUE;

undoit:
  /* Re-zero any output coefficients that we made newly nonzero */
  while (num_newnz > 0)
    (*block)[newnz_pos[--num_newnz]] = 0;

  return FALSE;
}


/*
 * Module initialization routine for progressive Huffman entropy decoding.
 */

GLOBAL(void)
jinit_phuff_decoder (j_decompress_ptr cinfo)
{
  phuff_entropy_ptr entropy;
  int *coef_bit_ptr;
  int ci, i;

  entropy = (phuff_entropy_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(phuff_entropy_decoder));
  cinfo->entropy = (struct jpeg_entropy_decoder *) entropy;
  entropy->pub.start_pass = start_pass_phuff_decoder;

  /* Mark derived tables unallocated */
  for (i = 0; i < NUM_HUFF_TBLS; i++) {
    entropy->derived_tbls[i] = NULL;
  }

  /* Create progression status table */
  cinfo->coef_bits = (int (*)[DCTSIZE2])
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				cinfo->num_components*DCTSIZE2*SIZEOF(int));
  coef_bit_ptr = & cinfo->coef_bits[0][0];
  for (ci = 0; ci < cinfo->num_components; ci++) 
    for (i = 0; i < DCTSIZE2; i++)
      *coef_bit_ptr++ = -1;
}

#endif /* D_PROGRESSIVE_SUPPORTED */

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdpostct.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the decompression postprocessing controller.
 * This controller manages the upsampling, color conversion, and color
 * quantization/reduction steps; specifically, it controls the buffering
 * between upsample/color conversion and color quantization/reduction.
 *
 * If no color quantization/reduction is required, then this module has no
 * work to do, and it just hands off to the upsample/color conversion code.
 * An integrated upsample/convert/quantize process would replace this module
 * entirely.
 */

/* Private buffer controller object */

typedef struct {
  struct jpeg_d_post_controller pub; /* public fields */

  /* Color quantization source buffer: this holds output data from
   * the upsample/color conversion step to be passed to the quantizer.
   * For two-pass color quantization, we need a full-image buffer;
   * for one-pass operation, a strip buffer is sufficient.
   */
  jvirt_sarray_ptr whole_image;	/* virtual array, or NULL if one-pass */
  JSAMPARRAY buffer;		/* strip buffer, or current strip of virtual */
  JDIMENSION strip_height;	/* buffer size in rows */
  /* for two-pass mode only: */
  JDIMENSION starting_row;	/* row # of first row in current strip */
  JDIMENSION next_row;		/* index of next row to fill/empty in strip */
} my_post_controller;

typedef my_post_controller * my_post_ptr;


/* Forward declarations */
METHODDEF(void) post_process_1pass
	JPP((j_decompress_ptr cinfo,
	     JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr,
	     JDIMENSION in_row_groups_avail,
	     JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
	     JDIMENSION out_rows_avail));


/*
 * Initialize for a processing pass.
 */

int start_pass_dpost (j_decompress_ptr cinfo, J_BUF_MODE pass_mode) {

  my_post_ptr post = (my_post_ptr) cinfo->post;

  switch (pass_mode) {
  case JBUF_PASS_THRU:
      /* For single-pass processing without color quantization,
       * I have no work to do; just call the upsampler directly.
       */
      post->pub.post_process_data = cinfo->upsample->upsample;
    break;
  default:
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
  }
  post->starting_row = post->next_row = 0;
	return 0;
}


/*
 * Process some data in the one-pass (strip buffer) case.
 * This is used for color precision reduction as well as one-pass quantization.
 */

METHODDEF(void)
post_process_1pass (j_decompress_ptr cinfo,
		    JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr,
		    JDIMENSION in_row_groups_avail,
		    JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
		    JDIMENSION out_rows_avail)
{
  my_post_ptr post = (my_post_ptr) cinfo->post;
  JDIMENSION num_rows, max_rows;

  /* Fill the buffer, but not more than what we can dump out in one go. */
  /* Note we rely on the upsampler to detect bottom of image. */
  max_rows = out_rows_avail - *out_row_ctr;
  if (max_rows > post->strip_height)
    max_rows = post->strip_height;
  num_rows = 0;
  (*cinfo->upsample->upsample) (cinfo,
		input_buf, in_row_group_ctr, in_row_groups_avail,
		post->buffer, &num_rows, max_rows);
  /* Quantize and emit data. */
  (*cinfo->cquantize->color_quantize) (cinfo,
		post->buffer, output_buf + *out_row_ctr, (int) num_rows);
  *out_row_ctr += num_rows;
}

/*
 * Initialize postprocessing controller.
 */

GLOBAL(void)
jinit_d_post_controller (j_decompress_ptr cinfo, boolean need_full_buffer)
{
  my_post_ptr post;

  post = (my_post_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_post_controller));
  cinfo->post = (struct jpeg_d_post_controller *) post;
  post->pub.start_pass = start_pass_dpost;
  post->whole_image = NULL;	/* flag for no virtual arrays */
  post->buffer = NULL;		/* flag for no strip buffer */
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jdsample.c
 *
 * Copyright (C) 1991-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains upsampling routines.
 *
 * Upsampling input data is counted in "row groups".  A row group
 * is defined to be (v_samp_factor * DCT_scaled_size / min_DCT_scaled_size)
 * sample rows of each component.  Upsampling will normally produce
 * max_v_samp_factor pixel rows from each row group (but this could vary
 * if the upsampler is applying a scale factor of its own).
 *
 * An excellent reference for image resampling is
 *   Digital Image Warping, George Wolberg, 1990.
 *   Pub. by IEEE Computer Society Press, Los Alamitos, CA. ISBN 0-8186-8944-7.
 */

/* Pointer to routine to upsample a single component */
typedef JMETHOD(void, upsample1_ptr,
		(j_decompress_ptr cinfo, jpeg_component_info * compptr,
		 JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr));

/* Private subobject */

typedef struct {
  struct jpeg_upsampler pub;	/* public fields */

  /* Color conversion buffer.  When using separate upsampling and color
   * conversion steps, this buffer holds one upsampled row group until it
   * has been color converted and output.
   * Note: we do not allocate any storage for component(s) which are full-size,
   * ie do not need rescaling.  The corresponding entry of color_buf[] is
   * simply set to point to the input data array, thereby avoiding copying.
   */
  JSAMPARRAY color_buf[MAX_COMPONENTS];

  /* Per-component upsampling method pointers */
  upsample1_ptr methods[MAX_COMPONENTS];

  int next_row_out;		/* counts rows emitted from color_buf */
  JDIMENSION rows_to_go;	/* counts rows remaining in image */

  /* Height of an input row group for each component. */
  int rowgroup_height[MAX_COMPONENTS];

  /* These arrays save pixel expansion factors so that int_expand need not
   * recompute them each time.  They are unused for other upsampling methods.
   */
  UINT8 h_expand[MAX_COMPONENTS];
  UINT8 v_expand[MAX_COMPONENTS];
} my_upsampler;

typedef my_upsampler * my_upsample_ptr;


/*
 * Initialize for an upsampling pass.
 */

int start_pass_upsample (j_decompress_ptr cinfo) {

  my_upsample_ptr upsample = (my_upsample_ptr) cinfo->upsample;

  /* Mark the conversion buffer empty */
  upsample->next_row_out = cinfo->max_v_samp_factor;
  /* Initialize total-height counter for detecting bottom of image */
  upsample->rows_to_go = cinfo->output_height;
	return 0;
}


/*
 * Control routine to do upsampling (and color conversion).
 *
 * In this version we upsample each component independently.
 * We upsample one row group into the conversion buffer, then apply
 * color conversion a row at a time.
 */

METHODDEF(void)
sep_upsample (j_decompress_ptr cinfo,
	      JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr,
	      JDIMENSION in_row_groups_avail,
	      JSAMPARRAY output_buf, JDIMENSION *out_row_ctr,
	      JDIMENSION out_rows_avail)
{
  my_upsample_ptr upsample = (my_upsample_ptr) cinfo->upsample;
  int ci;
  jpeg_component_info * compptr;
  JDIMENSION num_rows;

  /* Fill the conversion buffer, if it's empty */
  if (upsample->next_row_out >= cinfo->max_v_samp_factor) {
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
	 ci++, compptr++) {
      /* Invoke per-component upsample method.  Notice we pass a POINTER
       * to color_buf[ci], so that fullsize_upsample can change it.
       */
      (*upsample->methods[ci]) (cinfo, compptr,
	input_buf[ci] + (*in_row_group_ctr * upsample->rowgroup_height[ci]),
	upsample->color_buf + ci);
    }
    upsample->next_row_out = 0;
  }

  /* Color-convert and emit rows */

  /* How many we have in the buffer: */
  num_rows = (JDIMENSION) (cinfo->max_v_samp_factor - upsample->next_row_out);
  /* Not more than the distance to the end of the image.  Need this test
   * in case the image height is not a multiple of max_v_samp_factor:
   */
  if (num_rows > upsample->rows_to_go) 
    num_rows = upsample->rows_to_go;
  /* And not more than what the client can accept: */
  out_rows_avail -= *out_row_ctr;
  if (num_rows > out_rows_avail)
    num_rows = out_rows_avail;

  (*cinfo->cconvert->color_convert) (cinfo, upsample->color_buf,
				     (JDIMENSION) upsample->next_row_out,
				     output_buf + *out_row_ctr,
				     (int) num_rows);

  /* Adjust counts */
  *out_row_ctr += num_rows;
  upsample->rows_to_go -= num_rows;
  upsample->next_row_out += num_rows;
  /* When the buffer is emptied, declare this input row group consumed */
  if (upsample->next_row_out >= cinfo->max_v_samp_factor)
    (*in_row_group_ctr)++;
}


/*
 * These are the routines invoked by sep_upsample to upsample pixel values
 * of a single component.  One row group is processed per call.
 */


/*
 * For full-size components, we just make color_buf[ci] point at the
 * input buffer, and thus avoid copying any data.  Note that this is
 * safe only because sep_upsample doesn't declare the input row group
 * "consumed" until we are done color converting and emitting it.
 */

METHODDEF(void)
fullsize_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
		   JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  *output_data_ptr = input_data;
}


/*
 * This is a no-op version used for "uninteresting" components.
 * These components will not be referenced by color conversion.
 */

METHODDEF(void)
noop_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
	       JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  *output_data_ptr = NULL;	/* safety check */
}


/*
 * This version handles any integral sampling ratios.
 * This is not used for typical JPEG files, so it need not be fast.
 * Nor, for that matter, is it particularly accurate: the algorithm is
 * simple replication of the input pixel onto the corresponding output
 * pixels.  The hi-falutin sampling literature refers to this as a
 * "box filter".  A box filter tends to introduce visible artifacts,
 * so if you are actually going to use 3:1 or 4:1 sampling ratios
 * you would be well advised to improve this code.
 */

METHODDEF(void)
int_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
	      JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  my_upsample_ptr upsample = (my_upsample_ptr) cinfo->upsample;
  JSAMPARRAY output_data = *output_data_ptr;
  register JSAMPROW inptr, outptr;
  register JSAMPLE invalue;
  register int h;
  JSAMPROW outend;
  int h_expand, v_expand;
  int inrow, outrow;

  h_expand = upsample->h_expand[compptr->component_index];
  v_expand = upsample->v_expand[compptr->component_index];

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    /* Generate one output row with proper horizontal expansion */
    inptr = input_data[inrow];
    outptr = output_data[outrow];
    outend = outptr + cinfo->output_width;
    while (outptr < outend) {
      invalue = *inptr++;	/* don't need GETJSAMPLE() here */
      for (h = h_expand; h > 0; h--) {
	*outptr++ = invalue;
      }
    }
    /* Generate any additional output rows by duplicating the first one */
    if (v_expand > 1) {
      jcopy_sample_rows(output_data, outrow, output_data, outrow+1,
			v_expand-1, cinfo->output_width);
    }
    inrow++;
    outrow += v_expand;
  }
}


/*
 * Fast processing for the common case of 2:1 horizontal and 1:1 vertical.
 * It's still a box filter.
 */

METHODDEF(void)
h2v1_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
	       JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  register JSAMPROW inptr, outptr;
  register JSAMPLE invalue;
  JSAMPROW outend;
  int inrow;

  for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
    inptr = input_data[inrow];
    outptr = output_data[inrow];
    outend = outptr + cinfo->output_width;
    while (outptr < outend) {
      invalue = *inptr++;	/* don't need GETJSAMPLE() here */
      *outptr++ = invalue;
      *outptr++ = invalue;
    }
  }
}


/*
 * Fast processing for the common case of 2:1 horizontal and 2:1 vertical.
 * It's still a box filter.
 */

METHODDEF(void)
h2v2_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
	       JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  register JSAMPROW inptr, outptr;
  register JSAMPLE invalue;
  JSAMPROW outend;
  int inrow, outrow;

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    inptr = input_data[inrow];
    outptr = output_data[outrow];
    outend = outptr + cinfo->output_width;
    while (outptr < outend) {
      invalue = *inptr++;	/* don't need GETJSAMPLE() here */
      *outptr++ = invalue;
      *outptr++ = invalue;
    }
    jcopy_sample_rows(output_data, outrow, output_data, outrow+1,
		      1, cinfo->output_width);
    inrow++;
    outrow += 2;
  }
}


/*
 * Fancy processing for the common case of 2:1 horizontal and 1:1 vertical.
 *
 * The upsampling algorithm is linear interpolation between pixel centers,
 * also known as a "triangle filter".  This is a good compromise between
 * speed and visual quality.  The centers of the output pixels are 1/4 and 3/4
 * of the way between input pixel centers.
 *
 * A note about the "bias" calculations: when rounding fractional values to
 * integer, we do not want to always round 0.5 up to the next integer.
 * If we did that, we'd introduce a noticeable bias towards larger values.
 * Instead, this code is arranged so that 0.5 will be rounded up or down at
 * alternate pixel locations (a simple ordered dither pattern).
 */

METHODDEF(void)
h2v1_fancy_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
		     JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  register JSAMPROW inptr, outptr;
  register int invalue;
  register JDIMENSION colctr;
  int inrow;

  for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
    inptr = input_data[inrow];
    outptr = output_data[inrow];
    /* Special case for first column */
    invalue = GETJSAMPLE(*inptr++);
    *outptr++ = (JSAMPLE) invalue;
    *outptr++ = (JSAMPLE) ((invalue * 3 + GETJSAMPLE(*inptr) + 2) >> 2);

    for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
      /* General case: 3/4 * nearer pixel + 1/4 * further pixel */
      invalue = GETJSAMPLE(*inptr++) * 3;
      *outptr++ = (JSAMPLE) ((invalue + GETJSAMPLE(inptr[-2]) + 1) >> 2);
      *outptr++ = (JSAMPLE) ((invalue + GETJSAMPLE(*inptr) + 2) >> 2);
    }

    /* Special case for last column */
    invalue = GETJSAMPLE(*inptr);
    *outptr++ = (JSAMPLE) ((invalue * 3 + GETJSAMPLE(inptr[-1]) + 1) >> 2);
    *outptr++ = (JSAMPLE) invalue;
  }
}


/*
 * Fancy processing for the common case of 2:1 horizontal and 2:1 vertical.
 * Again a triangle filter; see comments for h2v1 case, above.
 *
 * It is OK for us to reference the adjacent input rows because we demanded
 * context from the main buffer controller (see initialization code).
 */

METHODDEF(void)
h2v2_fancy_upsample (j_decompress_ptr cinfo, jpeg_component_info * compptr,
		     JSAMPARRAY input_data, JSAMPARRAY * output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  register JSAMPROW inptr0, inptr1, outptr;
#if BITS_IN_JSAMPLE == 8
  register int thiscolsum, lastcolsum, nextcolsum;
#else
  register INT32 thiscolsum, lastcolsum, nextcolsum;
#endif
  register JDIMENSION colctr;
  int inrow, outrow, v;

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    for (v = 0; v < 2; v++) {
      /* inptr0 points to nearest input row, inptr1 points to next nearest */
      inptr0 = input_data[inrow];
      if (v == 0)		/* next nearest is row above */
	inptr1 = input_data[inrow-1];
      else			/* next nearest is row below */
	inptr1 = input_data[inrow+1];
      outptr = output_data[outrow++];

      /* Special case for first column */
      thiscolsum = GETJSAMPLE(*inptr0++) * 3 + GETJSAMPLE(*inptr1++);
      nextcolsum = GETJSAMPLE(*inptr0++) * 3 + GETJSAMPLE(*inptr1++);
      *outptr++ = (JSAMPLE) ((thiscolsum * 4 + 8) >> 4);
      *outptr++ = (JSAMPLE) ((thiscolsum * 3 + nextcolsum + 7) >> 4);
      lastcolsum = thiscolsum; thiscolsum = nextcolsum;

      for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
	/* General case: 3/4 * nearer pixel + 1/4 * further pixel in each */
	/* dimension, thus 9/16, 3/16, 3/16, 1/16 overall */
	nextcolsum = GETJSAMPLE(*inptr0++) * 3 + GETJSAMPLE(*inptr1++);
	*outptr++ = (JSAMPLE) ((thiscolsum * 3 + lastcolsum + 8) >> 4);
	*outptr++ = (JSAMPLE) ((thiscolsum * 3 + nextcolsum + 7) >> 4);
	lastcolsum = thiscolsum; thiscolsum = nextcolsum;
      }

      /* Special case for last column */
      *outptr++ = (JSAMPLE) ((thiscolsum * 3 + lastcolsum + 8) >> 4);
      *outptr++ = (JSAMPLE) ((thiscolsum * 4 + 7) >> 4);
    }
    inrow++;
  }
}


/*
 * Module initialization routine for upsampling.
 */

int jinit_upsampler (j_decompress_ptr cinfo) {

  my_upsample_ptr upsample;
  int ci;
  jpeg_component_info * compptr;
  boolean need_buffer, do_fancy;
  int h_in_group, v_in_group, h_out_group, v_out_group;

  upsample = (my_upsample_ptr)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				SIZEOF(my_upsampler));
  cinfo->upsample = (struct jpeg_upsampler *) upsample;
  upsample->pub.start_pass = start_pass_upsample;
  upsample->pub.upsample = sep_upsample;
  upsample->pub.need_context_rows = FALSE; /* until we find out differently */

  if (cinfo->CCIR601_sampling)	{/* this isn't supported */
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  /* jdmainct.c doesn't support context rows when min_DCT_scaled_size = 1,
   * so don't ask for it.
   */
  do_fancy = cinfo->do_fancy_upsampling && cinfo->min_DCT_scaled_size > 1;

  /* Verify we can handle the sampling factors, select per-component methods,
   * and create storage as needed.
   */
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    /* Compute size of an "input group" after IDCT scaling.  This many samples
     * are to be converted to max_h_samp_factor * max_v_samp_factor pixels.
     */
    h_in_group = (compptr->h_samp_factor * compptr->DCT_scaled_size) /
		 cinfo->min_DCT_scaled_size;
    v_in_group = (compptr->v_samp_factor * compptr->DCT_scaled_size) /
		 cinfo->min_DCT_scaled_size;
    h_out_group = cinfo->max_h_samp_factor;
    v_out_group = cinfo->max_v_samp_factor;
    upsample->rowgroup_height[ci] = v_in_group; /* save for use later */
    need_buffer = TRUE;
    if (! compptr->component_needed) {
      /* Don't bother to upsample an uninteresting component. */
      upsample->methods[ci] = noop_upsample;
      need_buffer = FALSE;
    } else if (h_in_group == h_out_group && v_in_group == v_out_group) {
      /* Fullsize components can be processed without any work. */
      upsample->methods[ci] = fullsize_upsample;
      need_buffer = FALSE;
    } else if (h_in_group * 2 == h_out_group &&
	       v_in_group == v_out_group) {
      /* Special cases for 2h1v upsampling */
      if (do_fancy && compptr->downsampled_width > 2)
	upsample->methods[ci] = h2v1_fancy_upsample;
      else
	upsample->methods[ci] = h2v1_upsample;
    } else if (h_in_group * 2 == h_out_group &&
	       v_in_group * 2 == v_out_group) {
      /* Special cases for 2h2v upsampling */
      if (do_fancy && compptr->downsampled_width > 2) {
	upsample->methods[ci] = h2v2_fancy_upsample;
	upsample->pub.need_context_rows = TRUE;
      } else
	upsample->methods[ci] = h2v2_upsample;
    } else if ((h_out_group % h_in_group) == 0 &&
	       (v_out_group % v_in_group) == 0) {
      /* Generic integral-factors upsampling method */
      upsample->methods[ci] = int_upsample;
      upsample->h_expand[ci] = (UINT8) (h_out_group / h_in_group);
      upsample->v_expand[ci] = (UINT8) (v_out_group / v_in_group);
    } else {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	  }
    if (need_buffer) {
      upsample->color_buf[ci] = (*cinfo->mem->alloc_sarray)
	((j_common_ptr) cinfo, JPOOL_IMAGE,
	 (JDIMENSION) jround_up((long) cinfo->output_width,
				(long) cinfo->max_h_samp_factor),
	 (JDIMENSION) cinfo->max_v_samp_factor);
    }
  }
	return 0;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jidctint.c
 *
 * Copyright (C) 1991-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains a slow-but-accurate integer implementation of the
 * inverse DCT (Discrete Cosine Transform).  In the IJG code, this routine
 * must also perform dequantization of the input coefficients.
 *
 * A 2-D IDCT can be done by 1-D IDCT on each column followed by 1-D IDCT
 * on each row (or vice versa, but it's more convenient to emit a row at
 * a time).  Direct algorithms are also available, but they are much more
 * complex and seem not to be any faster when reduced to code.
 *
 * This implementation is based on an algorithm described in
 *   C. Loeffler, A. Ligtenberg and G. Moschytz, "Practical Fast 1-D DCT
 *   Algorithms with 11 Multiplications", Proc. Int'l. Conf. on Acoustics,
 *   Speech, and Signal Processing 1989 (ICASSP '89), pp. 988-991.
 * The primary algorithm described there uses 11 multiplies and 29 adds.
 * We use their alternate method with 12 multiplies and 32 adds.
 * The advantage of this method is that no data path contains more than one
 * multiplication; this allows a very simple and accurate implementation in
 * scaled fixed-point arithmetic, with a minimal number of shifts.
 */


#ifdef DCT_ISLOW_SUPPORTED


/*
 * This module is specialized to the case DCTSIZE = 8.
 */

#if DCTSIZE != 8
  Sorry, this code only copes with 8x8 DCTs. /* deliberate syntax err */
#endif


/*
 * The poop on this scaling stuff is as follows:
 *
 * Each 1-D IDCT step produces outputs which are a factor of sqrt(N)
 * larger than the true IDCT outputs.  The final outputs are therefore
 * a factor of N larger than desired; since N=8 this can be cured by
 * a simple right shift at the end of the algorithm.  The advantage of
 * this arrangement is that we save two multiplications per 1-D IDCT,
 * because the y0 and y4 inputs need not be divided by sqrt(N).
 *
 * We have to do addition and subtraction of the integer inputs, which
 * is no problem, and multiplication by fractional constants, which is
 * a problem to do in integer arithmetic.  We multiply all the constants
 * by CONST_SCALE and convert them to integer constants (thus retaining
 * CONST_BITS bits of precision in the constants).  After doing a
 * multiplication we have to divide the product by CONST_SCALE, with proper
 * rounding, to produce the correct output.  This division can be done
 * cheaply as a right shift of CONST_BITS bits.  We postpone shifting
 * as long as possible so that partial sums can be added together with
 * full fractional precision.
 *
 * The outputs of the first pass are scaled up by PASS1_BITS bits so that
 * they are represented to better-than-integral precision.  These outputs
 * require BITS_IN_JSAMPLE + PASS1_BITS + 3 bits; this fits in a 16-bit word
 * with the recommended scaling.  (To scale up 12-bit sample data further, an
 * intermediate INT32 array would be needed.)
 *
 * To avoid overflow of the 32-bit intermediate results in pass 2, we must
 * have BITS_IN_JSAMPLE + CONST_BITS + PASS1_BITS <= 26.  Error analysis
 * shows that the values given below are the most effective.
 */

#if BITS_IN_JSAMPLE == 8
#define CONST_BITS  13
#define PASS1_BITS  2
#else
#define CONST_BITS  13
#define PASS1_BITS  1		/* lose a little precision to avoid overflow */
#endif

/* Some C compilers fail to reduce "FIX(constant)" at compile time, thus
 * causing a lot of useless floating-point operations at run time.
 * To get around this we use the following pre-calculated constants.
 * If you change CONST_BITS you may want to add appropriate values.
 * (With a reasonable C compiler, you can just rely on the FIX() macro...)
 */

#if CONST_BITS == 13
#define FIX_0_298631336  ((INT32)  2446)	/* FIX(0.298631336) */
#define FIX_0_390180644  ((INT32)  3196)	/* FIX(0.390180644) */
#define FIX_0_541196100  ((INT32)  4433)	/* FIX(0.541196100) */
#define FIX_0_765366865  ((INT32)  6270)	/* FIX(0.765366865) */
#define FIX_0_899976223  ((INT32)  7373)	/* FIX(0.899976223) */
#define FIX_1_175875602  ((INT32)  9633)	/* FIX(1.175875602) */
#define FIX_1_501321110  ((INT32)  12299)	/* FIX(1.501321110) */
#define FIX_1_847759065  ((INT32)  15137)	/* FIX(1.847759065) */
#define FIX_1_961570560  ((INT32)  16069)	/* FIX(1.961570560) */
#define FIX_2_053119869  ((INT32)  16819)	/* FIX(2.053119869) */
#define FIX_2_562915447  ((INT32)  20995)	/* FIX(2.562915447) */
#define FIX_3_072711026  ((INT32)  25172)	/* FIX(3.072711026) */
#else
#define FIX_0_298631336  FIX(0.298631336)
#define FIX_0_390180644  FIX(0.390180644)
#define FIX_0_541196100  FIX(0.541196100)
#define FIX_0_765366865  FIX(0.765366865)
#define FIX_0_899976223  FIX(0.899976223)
#define FIX_1_175875602  FIX(1.175875602)
#define FIX_1_501321110  FIX(1.501321110)
#define FIX_1_847759065  FIX(1.847759065)
#define FIX_1_961570560  FIX(1.961570560)
#define FIX_2_053119869  FIX(2.053119869)
#define FIX_2_562915447  FIX(2.562915447)
#define FIX_3_072711026  FIX(3.072711026)
#endif


/* Multiply an INT32 variable by an INT32 constant to yield an INT32 result.
 * For 8-bit samples with the recommended scaling, all the variable
 * and constant values involved are no more than 16 bits wide, so a
 * 16x16->32 bit multiply can be used instead of a full 32x32 multiply.
 * For 12-bit samples, a full 32-bit multiplication will be needed.
 */

#if BITS_IN_JSAMPLE == 8
#define MULTIPLY(var,const)  MULTIPLY16C16(var,const)
#else
#define MULTIPLY(var,const)  ((var) * (const))
#endif


/* Dequantize a coefficient by multiplying it by the multiplier-table
 * entry; produce an int result.  In this module, both inputs and result
 * are 16 bits or less, so either int or short multiply will work.
 */

#define DEQUANTIZE(coef,quantval)  (((ISLOW_MULT_TYPE) (coef)) * (quantval))


/*
 * Perform dequantization and inverse DCT on one block of coefficients.
 */

GLOBAL(void)
jpeg_idct_islow (j_decompress_ptr cinfo, jpeg_component_info * compptr,
		 JCOEFPTR coef_block,
		 JSAMPARRAY output_buf, JDIMENSION output_col)
{
  INT32 tmp0, tmp1, tmp2, tmp3;
  INT32 tmp10, tmp11, tmp12, tmp13;
  INT32 z1, z2, z3, z4, z5;
  JCOEFPTR inptr;
  ISLOW_MULT_TYPE * quantptr;
  int * wsptr;
  JSAMPROW outptr;
  JSAMPLE *range_limit = IDCT_range_limit(cinfo);
  int ctr;
  int workspace[DCTSIZE2];	/* buffers data between passes */
  SHIFT_TEMPS

  /* Pass 1: process columns from input, store into work array. */
  /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  inptr = coef_block;
  quantptr = (ISLOW_MULT_TYPE *) compptr->dct_table;
  wsptr = workspace;
  for (ctr = DCTSIZE; ctr > 0; ctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any column in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * column DCT calculations can be simplified this way.
     */
    
    if (inptr[DCTSIZE*1] == 0 && inptr[DCTSIZE*2] == 0 &&
	inptr[DCTSIZE*3] == 0 && inptr[DCTSIZE*4] == 0 &&
	inptr[DCTSIZE*5] == 0 && inptr[DCTSIZE*6] == 0 &&
	inptr[DCTSIZE*7] == 0) {
      /* AC terms all zero */
      int dcval = DEQUANTIZE(inptr[DCTSIZE*0], quantptr[DCTSIZE*0]) << PASS1_BITS;
      
      wsptr[DCTSIZE*0] = dcval;
      wsptr[DCTSIZE*1] = dcval;
      wsptr[DCTSIZE*2] = dcval;
      wsptr[DCTSIZE*3] = dcval;
      wsptr[DCTSIZE*4] = dcval;
      wsptr[DCTSIZE*5] = dcval;
      wsptr[DCTSIZE*6] = dcval;
      wsptr[DCTSIZE*7] = dcval;
      
      inptr++;			/* advance pointers to next column */
      quantptr++;
      wsptr++;
      continue;
    }
    
    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
    
    z2 = DEQUANTIZE(inptr[DCTSIZE*2], quantptr[DCTSIZE*2]);
    z3 = DEQUANTIZE(inptr[DCTSIZE*6], quantptr[DCTSIZE*6]);
    
    z1 = MULTIPLY(z2 + z3, FIX_0_541196100);
    tmp2 = z1 + MULTIPLY(z3, - FIX_1_847759065);
    tmp3 = z1 + MULTIPLY(z2, FIX_0_765366865);
    
    z2 = DEQUANTIZE(inptr[DCTSIZE*0], quantptr[DCTSIZE*0]);
    z3 = DEQUANTIZE(inptr[DCTSIZE*4], quantptr[DCTSIZE*4]);

    tmp0 = (z2 + z3) << CONST_BITS;
    tmp1 = (z2 - z3) << CONST_BITS;
    
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    
    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */
    
    tmp0 = DEQUANTIZE(inptr[DCTSIZE*7], quantptr[DCTSIZE*7]);
    tmp1 = DEQUANTIZE(inptr[DCTSIZE*5], quantptr[DCTSIZE*5]);
    tmp2 = DEQUANTIZE(inptr[DCTSIZE*3], quantptr[DCTSIZE*3]);
    tmp3 = DEQUANTIZE(inptr[DCTSIZE*1], quantptr[DCTSIZE*1]);
    
    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = MULTIPLY(z3 + z4, FIX_1_175875602); /* sqrt(2) * c3 */
    
    tmp0 = MULTIPLY(tmp0, FIX_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp1 = MULTIPLY(tmp1, FIX_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp2 = MULTIPLY(tmp2, FIX_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp3 = MULTIPLY(tmp3, FIX_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY(z1, - FIX_0_899976223); /* sqrt(2) * (c7-c3) */
    z2 = MULTIPLY(z2, - FIX_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY(z3, - FIX_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY(z4, - FIX_0_390180644); /* sqrt(2) * (c5-c3) */
    
    z3 += z5;
    z4 += z5;
    
    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;
    
    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */
    
    wsptr[DCTSIZE*0] = (int) DESCALE(tmp10 + tmp3, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*7] = (int) DESCALE(tmp10 - tmp3, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*1] = (int) DESCALE(tmp11 + tmp2, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*6] = (int) DESCALE(tmp11 - tmp2, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*2] = (int) DESCALE(tmp12 + tmp1, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*5] = (int) DESCALE(tmp12 - tmp1, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*3] = (int) DESCALE(tmp13 + tmp0, CONST_BITS-PASS1_BITS);
    wsptr[DCTSIZE*4] = (int) DESCALE(tmp13 - tmp0, CONST_BITS-PASS1_BITS);
    
    inptr++;			/* advance pointers to next column */
    quantptr++;
    wsptr++;
  }
  
  /* Pass 2: process rows from work array, store into output array. */
  /* Note that we must descale the results by a factor of 8 == 2**3, */
  /* and also undo the PASS1_BITS scaling. */

  wsptr = workspace;
  for (ctr = 0; ctr < DCTSIZE; ctr++) {
    outptr = output_buf[ctr] + output_col;
    /* Rows of zeroes can be exploited in the same way as we did with columns.
     * However, the column calculation has created many nonzero AC terms, so
     * the simplification applies less often (typically 5% to 10% of the time).
     * On machines with very fast multiplication, it's possible that the
     * test takes more time than it's worth.  In that case this section
     * may be commented out.
     */
    
#ifndef NO_ZERO_ROW_TEST
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 &&
	wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
      /* AC terms all zero */
      JSAMPLE dcval = range_limit[(int) DESCALE((INT32) wsptr[0], PASS1_BITS+3)
				  & RANGE_MASK];
      
      outptr[0] = dcval;
      outptr[1] = dcval;
      outptr[2] = dcval;
      outptr[3] = dcval;
      outptr[4] = dcval;
      outptr[5] = dcval;
      outptr[6] = dcval;
      outptr[7] = dcval;

      wsptr += DCTSIZE;		/* advance pointer to next row */
      continue;
    }
#endif
    
    /* Even part: reverse the even part of the forward DCT. */
    /* The rotator is sqrt(2)*c(-6). */
    
    z2 = (INT32) wsptr[2];
    z3 = (INT32) wsptr[6];
    
    z1 = MULTIPLY(z2 + z3, FIX_0_541196100);
    tmp2 = z1 + MULTIPLY(z3, - FIX_1_847759065);
    tmp3 = z1 + MULTIPLY(z2, FIX_0_765366865);
    
    tmp0 = ((INT32) wsptr[0] + (INT32) wsptr[4]) << CONST_BITS;
    tmp1 = ((INT32) wsptr[0] - (INT32) wsptr[4]) << CONST_BITS;
    
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    
    /* Odd part per figure 8; the matrix is unitary and hence its
     * transpose is its inverse.  i0..i3 are y7,y5,y3,y1 respectively.
     */
    
    tmp0 = (INT32) wsptr[7];
    tmp1 = (INT32) wsptr[5];
    tmp2 = (INT32) wsptr[3];
    tmp3 = (INT32) wsptr[1];
    
    z1 = tmp0 + tmp3;
    z2 = tmp1 + tmp2;
    z3 = tmp0 + tmp2;
    z4 = tmp1 + tmp3;
    z5 = MULTIPLY(z3 + z4, FIX_1_175875602); /* sqrt(2) * c3 */
    
    tmp0 = MULTIPLY(tmp0, FIX_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp1 = MULTIPLY(tmp1, FIX_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp2 = MULTIPLY(tmp2, FIX_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp3 = MULTIPLY(tmp3, FIX_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY(z1, - FIX_0_899976223); /* sqrt(2) * (c7-c3) */
    z2 = MULTIPLY(z2, - FIX_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY(z3, - FIX_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY(z4, - FIX_0_390180644); /* sqrt(2) * (c5-c3) */
    
    z3 += z5;
    z4 += z5;
    
    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;
    
    /* Final output stage: inputs are tmp10..tmp13, tmp0..tmp3 */
    
    outptr[0] = range_limit[(int) DESCALE(tmp10 + tmp3,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[7] = range_limit[(int) DESCALE(tmp10 - tmp3,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[1] = range_limit[(int) DESCALE(tmp11 + tmp2,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[6] = range_limit[(int) DESCALE(tmp11 - tmp2,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[2] = range_limit[(int) DESCALE(tmp12 + tmp1,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[5] = range_limit[(int) DESCALE(tmp12 - tmp1,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[3] = range_limit[(int) DESCALE(tmp13 + tmp0,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    outptr[4] = range_limit[(int) DESCALE(tmp13 - tmp0,
					  CONST_BITS+PASS1_BITS+3)
			    & RANGE_MASK];
    
    wsptr += DCTSIZE;		/* advance pointer to next row */
  }
}

#endif /* DCT_ISLOW_SUPPORTED */

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jmemmgr.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the JPEG system-independent memory management
 * routines.  This code is usable across a wide variety of machines; most
 * of the system dependencies have been isolated in a separate file.
 * The major functions provided here are:
 *   * pool-based allocation and freeing of memory;
 *   * policy decisions about how to divide available memory among the
 *     virtual arrays;
 *   * control logic for swapping virtual arrays between main memory and
 *     backing storage.
 * The separate system-dependent file provides the actual backing-storage
 * access code, and it contains the policy decision about how much total
 * main memory to use.
 * This file is system-dependent in the sense that some of its functions
 * are unnecessary in some systems.  For example, if there is enough virtual
 * memory so that backing storage will never be used, much of the virtual
 * array control logic could be removed.  (Of course, if you have that much
 * memory then you shouldn't care about a little bit of unused code...)
 */

#ifndef NO_GETENV
#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare getenv() */
extern char * getenv JPP((const char * name));
#endif
#endif


/*
 * Some important notes:
 *   The allocation routines provided here must never return NULL.
 *   They should exit to error_exit if unsuccessful.
 *
 *   It's not a good idea to try to merge the sarray and barray routines,
 *   even though they are textually almost the same, because samples are
 *   usually stored as bytes while coefficients are shorts or ints.  Thus,
 *   in machines where byte pointers have a different representation from
 *   word pointers, the resulting machine code could not be the same.
 */


/*
 * Many machines require storage alignment: longs must start on 4-byte
 * boundaries, doubles on 8-byte boundaries, etc.  On such machines, malloc()
 * always returns pointers that are multiples of the worst-case alignment
 * requirement, and we had better do so too.
 * There isn't any really portable way to determine the worst-case alignment
 * requirement.  This module assumes that the alignment requirement is
 * multiples of sizeof(ALIGN_TYPE).
 * By default, we define ALIGN_TYPE as double.  This is necessary on some
 * workstations (where doubles really do need 8-byte alignment) and will work
 * fine on nearly everything.  If your machine has lesser alignment needs,
 * you can save a few bytes by making ALIGN_TYPE smaller.
 * The only place I know of where this will NOT work is certain Macintosh
 * 680x0 compilers that define double as a 10-byte IEEE extended float.
 * Doing 10-byte alignment is counterproductive because longwords won't be
 * aligned well.  Put "#define ALIGN_TYPE long" in jconfig.h if you have
 * such a compiler.
 */

#ifndef ALIGN_TYPE		/* so can override from jconfig.h */
#define ALIGN_TYPE  double
#endif


/*
 * We allocate objects from "pools", where each pool is gotten with a single
 * request to jpeg_get_small() or jpeg_get_large().  There is no per-object
 * overhead within a pool, except for alignment padding.  Each pool has a
 * header with a link to the next pool of the same class.
 * Small and large pool headers are identical except that the latter's
 * link pointer must be FAR on 80x86 machines.
 * Notice that the "real" header fields are union'ed with a dummy ALIGN_TYPE
 * field.  This forces the compiler to make SIZEOF(small_pool_hdr) a multiple
 * of the alignment requirement of ALIGN_TYPE.
 */

typedef union small_pool_struct * small_pool_ptr;

typedef union small_pool_struct {
  struct {
    small_pool_ptr next;	/* next in list of pools */
    size_t bytes_used;		/* how many bytes already used within pool */
    size_t bytes_left;		/* bytes still available in this pool */
  } hdr;
  ALIGN_TYPE dummy;		/* included in union to ensure alignment */
} small_pool_hdr;

typedef union large_pool_struct  * large_pool_ptr;

typedef union large_pool_struct {
  struct {
    large_pool_ptr next;	/* next in list of pools */
    size_t bytes_used;		/* how many bytes already used within pool */
    size_t bytes_left;		/* bytes still available in this pool */
  } hdr;
  ALIGN_TYPE dummy;		/* included in union to ensure alignment */
} large_pool_hdr;


/*
 * Here is the full definition of a memory manager object.
 */

typedef struct {
  struct jpeg_memory_mgr pub;	/* public fields */

  /* Each pool identifier (lifetime class) names a linked list of pools. */
  small_pool_ptr small_list[JPOOL_NUMPOOLS];
  large_pool_ptr large_list[JPOOL_NUMPOOLS];

  /* Since we only have one lifetime class of virtual arrays, only one
   * linked list is necessary (for each datatype).  Note that the virtual
   * array control blocks being linked together are actually stored somewhere
   * in the small-pool list.
   */
  jvirt_sarray_ptr virt_sarray_list;
  jvirt_barray_ptr virt_barray_list;

  /* This counts total space obtained from jpeg_get_small/large */
  long total_space_allocated;

  /* alloc_sarray and alloc_barray set this value for use by virtual
   * array routines.
   */
  JDIMENSION last_rowsperchunk;	/* from most recent alloc_sarray/barray */
} my_memory_mgr;

typedef my_memory_mgr * my_mem_ptr;


/*
 * The control blocks for virtual arrays.
 * Note that these blocks are allocated in the "small" pool area.
 * System-dependent info for the associated backing store (if any) is hidden
 * inside the backing_store_info struct.
 */

struct jvirt_sarray_control {
  JSAMPARRAY mem_buffer;	/* => the in-memory buffer */
  JDIMENSION rows_in_array;	/* total virtual array height */
  JDIMENSION samplesperrow;	/* width of array (and of memory buffer) */
  JDIMENSION maxaccess;		/* max rows accessed by access_virt_sarray */
  JDIMENSION rows_in_mem;	/* height of memory buffer */
  JDIMENSION rowsperchunk;	/* allocation chunk size in mem_buffer */
  JDIMENSION cur_start_row;	/* first logical row # in the buffer */
  JDIMENSION first_undef_row;	/* row # of first uninitialized row */
  boolean pre_zero;		/* pre-zero mode requested? */
  boolean dirty;		/* do current buffer contents need written? */
  boolean b_s_open;		/* is backing-store data valid? */
  jvirt_sarray_ptr next;	/* link to next virtual sarray control block */
  backing_store_info b_s_info;	/* System-dependent control info */
};

struct jvirt_barray_control {
  JBLOCKARRAY mem_buffer;	/* => the in-memory buffer */
  JDIMENSION rows_in_array;	/* total virtual array height */
  JDIMENSION blocksperrow;	/* width of array (and of memory buffer) */
  JDIMENSION maxaccess;		/* max rows accessed by access_virt_barray */
  JDIMENSION rows_in_mem;	/* height of memory buffer */
  JDIMENSION rowsperchunk;	/* allocation chunk size in mem_buffer */
  JDIMENSION cur_start_row;	/* first logical row # in the buffer */
  JDIMENSION first_undef_row;	/* row # of first uninitialized row */
  boolean pre_zero;		/* pre-zero mode requested? */
  boolean dirty;		/* do current buffer contents need written? */
  boolean b_s_open;		/* is backing-store data valid? */
  jvirt_barray_ptr next;	/* link to next virtual barray control block */
  backing_store_info b_s_info;	/* System-dependent control info */
};


#ifdef MEM_STATS		/* optional extra stuff for statistics */

LOCAL(void)
print_mem_stats (j_common_ptr cinfo, int pool_id)
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  small_pool_ptr shdr_ptr;
  large_pool_ptr lhdr_ptr;

  /* Since this is only a debugging stub, we can cheat a little by using
   * fprintf directly rather than going through the trace message code.
   * This is helpful because message parm array can't handle longs.
   */
  fprintf(stderr, "Freeing pool %d, total space = %ld\n",
	  pool_id, mem->total_space_allocated);

  for (lhdr_ptr = mem->large_list[pool_id]; lhdr_ptr != NULL;
       lhdr_ptr = lhdr_ptr->hdr.next) {
    fprintf(stderr, "  Large chunk used %ld\n",
	    (long) lhdr_ptr->hdr.bytes_used);
  }

  for (shdr_ptr = mem->small_list[pool_id]; shdr_ptr != NULL;
       shdr_ptr = shdr_ptr->hdr.next) {
    fprintf(stderr, "  Small chunk used %ld free %ld\n",
	    (long) shdr_ptr->hdr.bytes_used,
	    (long) shdr_ptr->hdr.bytes_left);
  }
}

#endif /* MEM_STATS */


void * out_of_memory (j_common_ptr cinfo, int which)
/* Report an out-of-memory error and stop execution */
/* If we compiled MEM_STATS support, report alloc requests before dying */
{
#ifdef MEM_STATS
  cinfo->err->trace_level = 2;	/* force self_destruct to report stats */
#endif
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
}


/*
 * Allocation of "small" objects.
 *
 * For these, we use pooled storage.  When a new pool must be created,
 * we try to get enough space for the current request plus a "slop" factor,
 * where the slop will be the amount of leftover space in the new pool.
 * The speed vs. space tradeoff is largely determined by the slop values.
 * A different slop value is provided for each pool class (lifetime),
 * and we also distinguish the first pool of a class from later ones.
 * NOTE: the values given work fairly well on both 16- and 32-bit-int
 * machines, but may be too small if longs are 64 bits or more.
 */

static const size_t first_pool_slop[JPOOL_NUMPOOLS] = 
{
	1600,			/* first PERMANENT pool */
	16000			/* first IMAGE pool */
};

static const size_t extra_pool_slop[JPOOL_NUMPOOLS] = 
{
	0,			/* additional PERMANENT pools */
	5000			/* additional IMAGE pools */
};

#define MIN_SLOP  50		/* greater than 0 to avoid futile looping */


METHODDEF(void *)
alloc_small (j_common_ptr cinfo, int pool_id, size_t sizeofobject)
/* Allocate a "small" object */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  small_pool_ptr hdr_ptr, prev_hdr_ptr;
  char * data_ptr;
  size_t odd_bytes, min_request, slop;

  /* Check for unsatisfiable request (do now to ensure no overflow below) */
  if (sizeofobject > (size_t) (MAX_ALLOC_CHUNK-SIZEOF(small_pool_hdr))) {
    return out_of_memory(cinfo, 1);	/* request exceeds malloc's ability */
	}

  /* Round up the requested size to a multiple of SIZEOF(ALIGN_TYPE) */
  odd_bytes = sizeofobject % SIZEOF(ALIGN_TYPE);
  if (odd_bytes > 0)
    sizeofobject += SIZEOF(ALIGN_TYPE) - odd_bytes;

  /* See if space is available in any existing pool */
  if (pool_id < 0 || pool_id >= JPOOL_NUMPOOLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}
  prev_hdr_ptr = NULL;
  hdr_ptr = mem->small_list[pool_id];
  while (hdr_ptr != NULL) {
    if (hdr_ptr->hdr.bytes_left >= sizeofobject)
      break;			/* found pool with enough space */
    prev_hdr_ptr = hdr_ptr;
    hdr_ptr = hdr_ptr->hdr.next;
  }

  /* Time to make a new pool? */
  if (hdr_ptr == NULL) {
    /* min_request is what we need now, slop is what will be leftover */
    min_request = sizeofobject + SIZEOF(small_pool_hdr);
    if (prev_hdr_ptr == NULL)	/* first pool in class? */
      slop = first_pool_slop[pool_id];
    else
      slop = extra_pool_slop[pool_id];
    /* Don't ask for more than MAX_ALLOC_CHUNK */
    if (slop > (size_t) (MAX_ALLOC_CHUNK-min_request))
      slop = (size_t) (MAX_ALLOC_CHUNK-min_request);
    /* Try to get space, if fail reduce slop and try again */
    for (;;) {
      hdr_ptr = (small_pool_ptr) jpeg_get_small(cinfo, min_request + slop);
      if (hdr_ptr != NULL)
	break;
      slop /= 2;
      if (slop < MIN_SLOP) {	/* give up when it gets real small */
		return out_of_memory(cinfo, 2); /* jpeg_get_small failed */
		}
    }
    mem->total_space_allocated += min_request + slop;
    /* Success, initialize the new pool header and add to end of list */
    hdr_ptr->hdr.next = NULL;
    hdr_ptr->hdr.bytes_used = 0;
    hdr_ptr->hdr.bytes_left = sizeofobject + slop;
    if (prev_hdr_ptr == NULL)	/* first pool in class? */
      mem->small_list[pool_id] = hdr_ptr;
    else
      prev_hdr_ptr->hdr.next = hdr_ptr;
  }

  /* OK, allocate the object from the current pool */
  data_ptr = (char *) (hdr_ptr + 1); /* point to first data byte in pool */
  data_ptr += hdr_ptr->hdr.bytes_used; /* point to place for object */
  hdr_ptr->hdr.bytes_used += sizeofobject;
  hdr_ptr->hdr.bytes_left -= sizeofobject;

  return (void *) data_ptr;
}


/*
 * Allocation of "large" objects.
 *
 * The external semantics of these are the same as "small" objects,
 * except that FAR pointers are used on 80x86.  However the pool
 * management heuristics are quite different.  We assume that each
 * request is large enough that it may as well be passed directly to
 * jpeg_get_large; the pool management just links everything together
 * so that we can free it all on demand.
 * Note: the major use of "large" objects is in JSAMPARRAY and JBLOCKARRAY
 * structures.  The routines that create these structures (see below)
 * deliberately bunch rows together to ensure a large request size.
 */

METHODDEF(void  *)
alloc_large (j_common_ptr cinfo, int pool_id, size_t sizeofobject)
/* Allocate a "large" object */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  large_pool_ptr hdr_ptr;
  size_t odd_bytes;

  /* Check for unsatisfiable request (do now to ensure no overflow below) */
  if (sizeofobject > (size_t) (MAX_ALLOC_CHUNK-SIZEOF(large_pool_hdr))) {
    return out_of_memory(cinfo, 3);	/* request exceeds malloc's ability */
	}

  /* Round up the requested size to a multiple of SIZEOF(ALIGN_TYPE) */
  odd_bytes = sizeofobject % SIZEOF(ALIGN_TYPE);
  if (odd_bytes > 0)
    sizeofobject += SIZEOF(ALIGN_TYPE) - odd_bytes;

  /* Always make a new pool */
  if (pool_id < 0 || pool_id >= JPOOL_NUMPOOLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}

  hdr_ptr = (large_pool_ptr) jpeg_get_large(cinfo, sizeofobject +
					    SIZEOF(large_pool_hdr));
  if (hdr_ptr == NULL) {
    return out_of_memory(cinfo, 4);	/* jpeg_get_large failed */
	}
  mem->total_space_allocated += sizeofobject + SIZEOF(large_pool_hdr);

  /* Success, initialize the new pool header and add to list */
  hdr_ptr->hdr.next = mem->large_list[pool_id];
  /* We maintain space counts in each pool header for statistical purposes,
   * even though they are not needed for allocation.
   */
  hdr_ptr->hdr.bytes_used = sizeofobject;
  hdr_ptr->hdr.bytes_left = 0;
  mem->large_list[pool_id] = hdr_ptr;

  return (void  *) (hdr_ptr + 1); /* point to first data byte in pool */
}


/*
 * Creation of 2-D sample arrays.
 * The pointers are in near heap, the samples themselves in FAR heap.
 *
 * To minimize allocation overhead and to allow I/O of large contiguous
 * blocks, we allocate the sample rows in groups of as many rows as possible
 * without exceeding MAX_ALLOC_CHUNK total bytes per allocation request.
 * NB: the virtual array control routines, later in this file, know about
 * this chunking of rows.  The rowsperchunk value is left in the mem manager
 * object so that it can be saved away if this sarray is the workspace for
 * a virtual array.
 */

METHODDEF(JSAMPARRAY)
alloc_sarray (j_common_ptr cinfo, int pool_id,
	      JDIMENSION samplesperrow, JDIMENSION numrows)
/* Allocate a 2-D sample array */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  JSAMPARRAY result;
  JSAMPROW workspace;
  JDIMENSION rowsperchunk, currow, i;
  long ltemp;

  /* Calculate max # of rows allowed in one allocation chunk */
  ltemp = (MAX_ALLOC_CHUNK-SIZEOF(large_pool_hdr)) /
	  ((long) samplesperrow * SIZEOF(JSAMPLE));
  if (ltemp <= 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}
  if (ltemp < (long) numrows)
    rowsperchunk = (JDIMENSION) ltemp;
  else
    rowsperchunk = numrows;
  mem->last_rowsperchunk = rowsperchunk;

  /* Get space for row pointers (small object) */
  result = (JSAMPARRAY) alloc_small(cinfo, pool_id,
				    (size_t) (numrows * SIZEOF(JSAMPROW)));

  /* Get the rows themselves (large objects) */
  currow = 0;
  while (currow < numrows) {
    rowsperchunk = MIN(rowsperchunk, numrows - currow);
    workspace = (JSAMPROW) alloc_large(cinfo, pool_id,
	(size_t) ((size_t) rowsperchunk * (size_t) samplesperrow
		  * SIZEOF(JSAMPLE)));
    for (i = rowsperchunk; i > 0; i--) {
      result[currow++] = workspace;
      workspace += samplesperrow;
    }
  }

  return result;
}


/*
 * Creation of 2-D coefficient-block arrays.
 * This is essentially the same as the code for sample arrays, above.
 */

METHODDEF(JBLOCKARRAY)
alloc_barray (j_common_ptr cinfo, int pool_id,
	      JDIMENSION blocksperrow, JDIMENSION numrows)
/* Allocate a 2-D coefficient-block array */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  JBLOCKARRAY result;
  JBLOCKROW workspace;
  JDIMENSION rowsperchunk, currow, i;
  long ltemp;

  /* Calculate max # of rows allowed in one allocation chunk */
  ltemp = (MAX_ALLOC_CHUNK-SIZEOF(large_pool_hdr)) /
	  ((long) blocksperrow * SIZEOF(JBLOCK));
  if (ltemp <= 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}
  if (ltemp < (long) numrows)
    rowsperchunk = (JDIMENSION) ltemp;
  else
    rowsperchunk = numrows;
  mem->last_rowsperchunk = rowsperchunk;

  /* Get space for row pointers (small object) */
  result = (JBLOCKARRAY) alloc_small(cinfo, pool_id,
				     (size_t) (numrows * SIZEOF(JBLOCKROW)));

  /* Get the rows themselves (large objects) */
  currow = 0;
  while (currow < numrows) {
    rowsperchunk = MIN(rowsperchunk, numrows - currow);
    workspace = (JBLOCKROW) alloc_large(cinfo, pool_id,
	(size_t) ((size_t) rowsperchunk * (size_t) blocksperrow
		  * SIZEOF(JBLOCK)));
    for (i = rowsperchunk; i > 0; i--) {
      result[currow++] = workspace;
      workspace += blocksperrow;
    }
  }

  return result;
}


/*
 * About virtual array management:
 *
 * The above "normal" array routines are only used to allocate strip buffers
 * (as wide as the image, but just a few rows high).  Full-image-sized buffers
 * are handled as "virtual" arrays.  The array is still accessed a strip at a
 * time, but the memory manager must save the whole array for repeated
 * accesses.  The intended implementation is that there is a strip buffer in
 * memory (as high as is possible given the desired memory limit), plus a
 * backing file that holds the rest of the array.
 *
 * The request_virt_array routines are told the total size of the image and
 * the maximum number of rows that will be accessed at once.  The in-memory
 * buffer must be at least as large as the maxaccess value.
 *
 * The request routines create control blocks but not the in-memory buffers.
 * That is postponed until realize_virt_arrays is called.  At that time the
 * total amount of space needed is known (approximately, anyway), so free
 * memory can be divided up fairly.
 *
 * The access_virt_array routines are responsible for making a specific strip
 * area accessible (after reading or writing the backing file, if necessary).
 * Note that the access routines are told whether the caller intends to modify
 * the accessed strip; during a read-only pass this saves having to rewrite
 * data to disk.  The access routines are also responsible for pre-zeroing
 * any newly accessed rows, if pre-zeroing was requested.
 *
 * In current usage, the access requests are usually for nonoverlapping
 * strips; that is, successive access start_row numbers differ by exactly
 * num_rows = maxaccess.  This means we can get good performance with simple
 * buffer dump/reload logic, by making the in-memory buffer be a multiple
 * of the access height; then there will never be accesses across bufferload
 * boundaries.  The code will still work with overlapping access requests,
 * but it doesn't handle bufferload overlaps very efficiently.
 */


METHODDEF(jvirt_sarray_ptr)
request_virt_sarray (j_common_ptr cinfo, int pool_id, boolean pre_zero,
		     JDIMENSION samplesperrow, JDIMENSION numrows,
		     JDIMENSION maxaccess)
/* Request a virtual 2-D sample array */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  jvirt_sarray_ptr result;

  /* Only IMAGE-lifetime virtual arrays are currently supported */
  if (pool_id != JPOOL_IMAGE) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}

  /* get control block */
  result = (jvirt_sarray_ptr) alloc_small(cinfo, pool_id,
					  SIZEOF(struct jvirt_sarray_control));

  result->mem_buffer = NULL;	/* marks array not yet realized */
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = FALSE;	/* no associated backing-store object */
  result->next = mem->virt_sarray_list; /* add to list of virtual arrays */
  mem->virt_sarray_list = result;

  return result;
}


METHODDEF(jvirt_barray_ptr)
request_virt_barray (j_common_ptr cinfo, int pool_id, boolean pre_zero,
		     JDIMENSION blocksperrow, JDIMENSION numrows,
		     JDIMENSION maxaccess)
/* Request a virtual 2-D coefficient-block array */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  jvirt_barray_ptr result;

  /* Only IMAGE-lifetime virtual arrays are currently supported */
  if (pool_id != JPOOL_IMAGE) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}

  /* get control block */
  result = (jvirt_barray_ptr) alloc_small(cinfo, pool_id,
					  SIZEOF(struct jvirt_barray_control));

  result->mem_buffer = NULL;	/* marks array not yet realized */
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = FALSE;	/* no associated backing-store object */
  result->next = mem->virt_barray_list; /* add to list of virtual arrays */
  mem->virt_barray_list = result;

  return result;
}


METHODDEF(void)
realize_virt_arrays (j_common_ptr cinfo)
/* Allocate the in-memory buffers for any unrealized virtual arrays */
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  long space_per_minheight, maximum_space, avail_mem;
  long minheights, max_minheights;
  jvirt_sarray_ptr sptr;
  jvirt_barray_ptr bptr;

  /* Compute the minimum space needed (maxaccess rows in each buffer)
   * and the maximum space needed (full image height in each buffer).
   * These may be of use to the system-dependent jpeg_mem_available routine.
   */
  space_per_minheight = 0;
  maximum_space = 0;
  for (sptr = mem->virt_sarray_list; sptr != NULL; sptr = sptr->next) {
    if (sptr->mem_buffer == NULL) { /* if not realized yet */
      space_per_minheight += (long) sptr->maxaccess *
			     (long) sptr->samplesperrow * SIZEOF(JSAMPLE);
      maximum_space += (long) sptr->rows_in_array *
		       (long) sptr->samplesperrow * SIZEOF(JSAMPLE);
    }
  }
  for (bptr = mem->virt_barray_list; bptr != NULL; bptr = bptr->next) {
    if (bptr->mem_buffer == NULL) { /* if not realized yet */
      space_per_minheight += (long) bptr->maxaccess *
			     (long) bptr->blocksperrow * SIZEOF(JBLOCK);
      maximum_space += (long) bptr->rows_in_array *
		       (long) bptr->blocksperrow * SIZEOF(JBLOCK);
    }
  }

  if (space_per_minheight <= 0)
    return;			/* no unrealized arrays, no work */

  /* Determine amount of memory to actually use; this is system-dependent. */
  avail_mem = jpeg_mem_available(cinfo, space_per_minheight, maximum_space,
				 mem->total_space_allocated);

  /* If the maximum space needed is available, make all the buffers full
   * height; otherwise parcel it out with the same number of minheights
   * in each buffer.
   */
  if (avail_mem >= maximum_space)
    max_minheights = 1000000000L;
  else {
    max_minheights = avail_mem / space_per_minheight;
    /* If there doesn't seem to be enough space, try to get the minimum
     * anyway.  This allows a "stub" implementation of jpeg_mem_available().
     */
    if (max_minheights <= 0)
      max_minheights = 1;
  }

  /* Allocate the in-memory buffers and initialize backing store as needed. */

  for (sptr = mem->virt_sarray_list; sptr != NULL; sptr = sptr->next) {
    if (sptr->mem_buffer == NULL) { /* if not realized yet */
      minheights = ((long) sptr->rows_in_array - 1L) / sptr->maxaccess + 1L;
      if (minheights <= max_minheights) {
	/* This buffer fits in memory */
	sptr->rows_in_mem = sptr->rows_in_array;
      } else {
	/* It doesn't fit in memory, create backing store. */
	sptr->rows_in_mem = (JDIMENSION) (max_minheights * sptr->maxaccess);
	jpeg_open_backing_store(cinfo, & sptr->b_s_info, (long) sptr->rows_in_array * (long) sptr->samplesperrow * (long) SIZEOF(JSAMPLE));
	sptr->b_s_open = TRUE;
      }
      sptr->mem_buffer = alloc_sarray(cinfo, JPOOL_IMAGE,
				      sptr->samplesperrow, sptr->rows_in_mem);
      sptr->rowsperchunk = mem->last_rowsperchunk;
      sptr->cur_start_row = 0;
      sptr->first_undef_row = 0;
      sptr->dirty = FALSE;
    }
  }

  for (bptr = mem->virt_barray_list; bptr != NULL; bptr = bptr->next) {
    if (bptr->mem_buffer == NULL) { /* if not realized yet */
      minheights = ((long) bptr->rows_in_array - 1L) / bptr->maxaccess + 1L;
      if (minheights <= max_minheights) {
	/* This buffer fits in memory */
	bptr->rows_in_mem = bptr->rows_in_array;
      } else {
	/* It doesn't fit in memory, create backing store. */
	bptr->rows_in_mem = (JDIMENSION) (max_minheights * bptr->maxaccess);
	jpeg_open_backing_store(cinfo, & bptr->b_s_info,
				(long) bptr->rows_in_array *
				(long) bptr->blocksperrow *
				(long) SIZEOF(JBLOCK));
	bptr->b_s_open = TRUE;
      }
      bptr->mem_buffer = alloc_barray(cinfo, JPOOL_IMAGE,
				      bptr->blocksperrow, bptr->rows_in_mem);
      bptr->rowsperchunk = mem->last_rowsperchunk;
      bptr->cur_start_row = 0;
      bptr->first_undef_row = 0;
      bptr->dirty = FALSE;
    }
  }
}


LOCAL(void)
do_sarray_io (j_common_ptr cinfo, jvirt_sarray_ptr ptr, boolean writing)
/* Do backing store read or write of a virtual sample array */
{
  long bytesperrow, file_offset, byte_count, rows, thisrow, i;

  bytesperrow = (long) ptr->samplesperrow * SIZEOF(JSAMPLE);
  file_offset = ptr->cur_start_row * bytesperrow;
  /* Loop to read or write each allocation chunk in mem_buffer */
  for (i = 0; i < (long) ptr->rows_in_mem; i += ptr->rowsperchunk) {
    /* One chunk, but check for short chunk at end of buffer */
    rows = MIN((long) ptr->rowsperchunk, (long) ptr->rows_in_mem - i);
    /* Transfer no more than is currently defined */
    thisrow = (long) ptr->cur_start_row + i;
    rows = MIN(rows, (long) ptr->first_undef_row - thisrow);
    /* Transfer no more than fits in file */
    rows = MIN(rows, (long) ptr->rows_in_array - thisrow);
    if (rows <= 0)		/* this chunk might be past end of file! */
      break;
    byte_count = rows * bytesperrow;
    if (writing)
      (*ptr->b_s_info.write_backing_store) (cinfo, & ptr->b_s_info,
					    (void  *) ptr->mem_buffer[i],
					    file_offset, byte_count);
    else
      (*ptr->b_s_info.read_backing_store) (cinfo, & ptr->b_s_info,
					   (void  *) ptr->mem_buffer[i],
					   file_offset, byte_count);
    file_offset += byte_count;
  }
}


LOCAL(void)
do_barray_io (j_common_ptr cinfo, jvirt_barray_ptr ptr, boolean writing)
/* Do backing store read or write of a virtual coefficient-block array */
{
  long bytesperrow, file_offset, byte_count, rows, thisrow, i;

  bytesperrow = (long) ptr->blocksperrow * SIZEOF(JBLOCK);
  file_offset = ptr->cur_start_row * bytesperrow;
  /* Loop to read or write each allocation chunk in mem_buffer */
  for (i = 0; i < (long) ptr->rows_in_mem; i += ptr->rowsperchunk) {
    /* One chunk, but check for short chunk at end of buffer */
    rows = MIN((long) ptr->rowsperchunk, (long) ptr->rows_in_mem - i);
    /* Transfer no more than is currently defined */
    thisrow = (long) ptr->cur_start_row + i;
    rows = MIN(rows, (long) ptr->first_undef_row - thisrow);
    /* Transfer no more than fits in file */
    rows = MIN(rows, (long) ptr->rows_in_array - thisrow);
    if (rows <= 0)		/* this chunk might be past end of file! */
      break;
    byte_count = rows * bytesperrow;
    if (writing)
      (*ptr->b_s_info.write_backing_store) (cinfo, & ptr->b_s_info,
					    (void  *) ptr->mem_buffer[i],
					    file_offset, byte_count);
    else
      (*ptr->b_s_info.read_backing_store) (cinfo, & ptr->b_s_info,
					   (void  *) ptr->mem_buffer[i],
					   file_offset, byte_count);
    file_offset += byte_count;
  }
}


METHODDEF(JSAMPARRAY)
access_virt_sarray (j_common_ptr cinfo, jvirt_sarray_ptr ptr,
		    JDIMENSION start_row, JDIMENSION num_rows,
		    boolean writable)
/* Access the part of a virtual sample array starting at start_row */
/* and extending for num_rows rows.  writable is true if  */
/* caller intends to modify the accessed area. */
{
  JDIMENSION end_row = start_row + num_rows;
  JDIMENSION undef_row;

  /* debugging check */
  if( end_row > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == NULL) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}

  /* Make the desired part of the virtual array accessible */
  if (start_row < ptr->cur_start_row ||
      end_row > ptr->cur_start_row+ptr->rows_in_mem) {
    if (! ptr->b_s_open) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	  }
    /* Flush old buffer contents if necessary */
    if (ptr->dirty) {
      do_sarray_io(cinfo, ptr, TRUE);
      ptr->dirty = FALSE;
    }
    /* Decide what part of virtual array to access.
     * Algorithm: if target address > current window, assume forward scan,
     * load starting at target address.  If target address < current window,
     * assume backward scan, load so that target area is top of window.
     * Note that when switching from forward write to forward read, will have
     * start_row = 0, so the limiting case applies and we load from 0 anyway.
     */
    if (start_row > ptr->cur_start_row) {
      ptr->cur_start_row = start_row;
    } else {
      /* use long arithmetic here to avoid overflow & unsigned problems */
      long ltemp;

      ltemp = (long) end_row - (long) ptr->rows_in_mem;
      if (ltemp < 0)
	ltemp = 0;		/* don't fall off front end of file */
      ptr->cur_start_row = (JDIMENSION) ltemp;
    }
    /* Read in the selected part of the array.
     * During the initial write pass, we will do no actual read
     * because the selected part is all undefined.
     */
    do_sarray_io(cinfo, ptr, FALSE);
  }
  /* Ensure the accessed part of the array is defined; prezero if needed.
   * To improve locality of access, we only prezero the part of the array
   * that the caller is about to access, not the entire in-memory array.
   */
  if (ptr->first_undef_row < end_row) {
    if (ptr->first_undef_row < start_row) {
      if (writable)	{	/* writer skipped over a section of array */
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
		}
      undef_row = start_row;	/* but reader is allowed to read ahead */
    } else {
      undef_row = ptr->first_undef_row;
    }
    if (writable)
      ptr->first_undef_row = end_row;
    if (ptr->pre_zero) {
      size_t bytesperrow = (size_t) ptr->samplesperrow * SIZEOF(JSAMPLE);
      undef_row -= ptr->cur_start_row; /* make indexes relative to buffer */
      end_row -= ptr->cur_start_row;
      while (undef_row < end_row) {
	jzero_far((void  *) ptr->mem_buffer[undef_row], bytesperrow);
	undef_row++;
      }
    } else {
      if (! writable) {		/* reader looking at undefined data */
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
		}
    }
  }
  /* Flag the buffer dirty if caller will write in it */
  if (writable)
    ptr->dirty = TRUE;
  /* Return address of proper part of the buffer */
  return ptr->mem_buffer + (start_row - ptr->cur_start_row);
}


METHODDEF(JBLOCKARRAY)
access_virt_barray (j_common_ptr cinfo, jvirt_barray_ptr ptr,
		    JDIMENSION start_row, JDIMENSION num_rows,
		    boolean writable)
/* Access the part of a virtual block array starting at start_row */
/* and extending for num_rows rows.  writable is true if  */
/* caller intends to modify the accessed area. */
{
  JDIMENSION end_row = start_row + num_rows;
  JDIMENSION undef_row;

  /* debugging check */
  if (end_row > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == NULL) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	}

  /* Make the desired part of the virtual array accessible */
  if (start_row < ptr->cur_start_row ||
      end_row > ptr->cur_start_row+ptr->rows_in_mem) {
    if (! ptr->b_s_open) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
	  }
    /* Flush old buffer contents if necessary */
    if (ptr->dirty) {
      do_barray_io(cinfo, ptr, TRUE);
      ptr->dirty = FALSE;
    }
    /* Decide what part of virtual array to access.
     * Algorithm: if target address > current window, assume forward scan,
     * load starting at target address.  If target address < current window,
     * assume backward scan, load so that target area is top of window.
     * Note that when switching from forward write to forward read, will have
     * start_row = 0, so the limiting case applies and we load from 0 anyway.
     */
    if (start_row > ptr->cur_start_row) {
      ptr->cur_start_row = start_row;
    } else {
      /* use long arithmetic here to avoid overflow & unsigned problems */
      long ltemp;

      ltemp = (long) end_row - (long) ptr->rows_in_mem;
      if (ltemp < 0)
	ltemp = 0;		/* don't fall off front end of file */
      ptr->cur_start_row = (JDIMENSION) ltemp;
    }
    /* Read in the selected part of the array.
     * During the initial write pass, we will do no actual read
     * because the selected part is all undefined.
     */
    do_barray_io(cinfo, ptr, FALSE);
  }
  /* Ensure the accessed part of the array is defined; prezero if needed.
   * To improve locality of access, we only prezero the part of the array
   * that the caller is about to access, not the entire in-memory array.
   */
  if (ptr->first_undef_row < end_row) {
    if (ptr->first_undef_row < start_row) {
      if (writable)	{	/* writer skipped over a section of array */
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
		}
      undef_row = start_row;	/* but reader is allowed to read ahead */
    } else {
      undef_row = ptr->first_undef_row;
    }
    if (writable)
      ptr->first_undef_row = end_row;
    if (ptr->pre_zero) {
      size_t bytesperrow = (size_t) ptr->blocksperrow * SIZEOF(JBLOCK);
      undef_row -= ptr->cur_start_row; /* make indexes relative to buffer */
      end_row -= ptr->cur_start_row;
      while (undef_row < end_row) {
	jzero_far((void  *) ptr->mem_buffer[undef_row], bytesperrow);
	undef_row++;
      }
    } else {
      if (! writable) {		/* reader looking at undefined data */
		jpeg_destroy((j_common_ptr)&cinfo);
		return NULL;
		}
    }
  }
  /* Flag the buffer dirty if caller will write in it */
  if (writable)
    ptr->dirty = TRUE;
  /* Return address of proper part of the buffer */
  return ptr->mem_buffer + (start_row - ptr->cur_start_row);
}


/*
 * Release all objects belonging to a specified pool.
 */

METHODDEF(void)
free_pool (j_common_ptr cinfo, int pool_id)
{
  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
  small_pool_ptr shdr_ptr;
  large_pool_ptr lhdr_ptr;
  size_t space_freed;

  if (pool_id < 0 || pool_id >= JPOOL_NUMPOOLS) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return;
	}

#ifdef MEM_STATS
  if (cinfo->err->trace_level > 1)
    print_mem_stats(cinfo, pool_id); /* print pool's memory usage statistics */
#endif

  /* If freeing IMAGE pool, close any virtual arrays first */
  if (pool_id == JPOOL_IMAGE) {
    jvirt_sarray_ptr sptr;
    jvirt_barray_ptr bptr;

    for (sptr = mem->virt_sarray_list; sptr != NULL; sptr = sptr->next) {
      if (sptr->b_s_open) {	/* there may be no backing store */
	sptr->b_s_open = FALSE;	/* prevent recursive close if error */
	(*sptr->b_s_info.close_backing_store) (cinfo, & sptr->b_s_info);
      }
    }
    mem->virt_sarray_list = NULL;
    for (bptr = mem->virt_barray_list; bptr != NULL; bptr = bptr->next) {
      if (bptr->b_s_open) {	/* there may be no backing store */
	bptr->b_s_open = FALSE;	/* prevent recursive close if error */
	(*bptr->b_s_info.close_backing_store) (cinfo, & bptr->b_s_info);
      }
    }
    mem->virt_barray_list = NULL;
  }

  /* Release large objects */
  lhdr_ptr = mem->large_list[pool_id];
  mem->large_list[pool_id] = NULL;

  while (lhdr_ptr != NULL) {
    large_pool_ptr next_lhdr_ptr = lhdr_ptr->hdr.next;
    space_freed = lhdr_ptr->hdr.bytes_used +
		  lhdr_ptr->hdr.bytes_left +
		  SIZEOF(large_pool_hdr);
    jpeg_free_large(cinfo, (void  *) lhdr_ptr, space_freed);
    mem->total_space_allocated -= space_freed;
    lhdr_ptr = next_lhdr_ptr;
  }

  /* Release small objects */
  shdr_ptr = mem->small_list[pool_id];
  mem->small_list[pool_id] = NULL;

  while (shdr_ptr != NULL) {
    small_pool_ptr next_shdr_ptr = shdr_ptr->hdr.next;
    space_freed = shdr_ptr->hdr.bytes_used +
		  shdr_ptr->hdr.bytes_left +
		  SIZEOF(small_pool_hdr);
    jpeg_free_small(cinfo, (void *) shdr_ptr, space_freed);
    mem->total_space_allocated -= space_freed;
    shdr_ptr = next_shdr_ptr;
  }
}


/*
 * Close up shop entirely.
 * Note that this cannot be called unless cinfo->mem is non-NULL.
 */

METHODDEF(void)
self_destruct (j_common_ptr cinfo)
{
  int pool;

  /* Close all backing store, release all memory.
   * Releasing pools in reverse order might help avoid fragmentation
   * with some (brain-damaged) malloc libraries.
   */
  for (pool = JPOOL_NUMPOOLS-1; pool >= JPOOL_PERMANENT; pool--) {
    free_pool(cinfo, pool);
  }

  /* Release the memory manager control block too. */
  jpeg_free_small(cinfo, (void *) cinfo->mem, SIZEOF(my_memory_mgr));
  cinfo->mem = NULL;		/* ensures I will be called only once */

  jpeg_mem_term(cinfo);		/* system-dependent cleanup */
}


/*
 * Memory manager initialization.
 * When this is called, only the error manager pointer is valid in cinfo!
 */

int jinit_memory_mgr (j_common_ptr cinfo) {

  my_mem_ptr mem;
  long max_to_use;
  int pool;
  size_t test_mac;

  cinfo->mem = NULL;		/* for safety if init fails */

  /* Check for configuration errors.
   * SIZEOF(ALIGN_TYPE) should be a power of 2; otherwise, it probably
   * doesn't reflect any real hardware alignment requirement.
   * The test is a little tricky: for X>0, X and X-1 have no one-bits
   * in common if and only if X is a power of 2, ie has only one one-bit.
   * Some compilers may give an "unreachable code" warning here; ignore it.
   */
  if ((SIZEOF(ALIGN_TYPE) & (SIZEOF(ALIGN_TYPE)-1)) != 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
  /* MAX_ALLOC_CHUNK must be representable as type size_t, and must be
   * a multiple of SIZEOF(ALIGN_TYPE).
   * Again, an "unreachable code" warning may be ignored here.
   * But a "constant too large" warning means you need to fix MAX_ALLOC_CHUNK.
   */
  test_mac = (size_t) MAX_ALLOC_CHUNK;
  if ((long) test_mac != MAX_ALLOC_CHUNK || (MAX_ALLOC_CHUNK % SIZEOF(ALIGN_TYPE)) != 0) {
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}

  max_to_use = jpeg_mem_init(cinfo); /* system-dependent initialization */

  /* Attempt to allocate memory manager's control block */
  mem = (my_mem_ptr) jpeg_get_small(cinfo, SIZEOF(my_memory_mgr));

  if (mem == NULL) {
    jpeg_mem_term(cinfo);	/* system-dependent cleanup */
	jpeg_destroy((j_common_ptr)&cinfo);
	return -1;
  }

  /* OK, fill in the method pointers */
  mem->pub.alloc_small = alloc_small;
  mem->pub.alloc_large = alloc_large;
  mem->pub.alloc_sarray = alloc_sarray;
  mem->pub.alloc_barray = alloc_barray;
  mem->pub.request_virt_sarray = request_virt_sarray;
  mem->pub.request_virt_barray = request_virt_barray;
  mem->pub.realize_virt_arrays = realize_virt_arrays;
  mem->pub.access_virt_sarray = access_virt_sarray;
  mem->pub.access_virt_barray = access_virt_barray;
  mem->pub.free_pool = free_pool;
  mem->pub.self_destruct = self_destruct;

  /* Make MAX_ALLOC_CHUNK accessible to other modules */
  mem->pub.max_alloc_chunk = MAX_ALLOC_CHUNK;

  /* Initialize working state */
  mem->pub.max_memory_to_use = max_to_use;

  for (pool = JPOOL_NUMPOOLS-1; pool >= JPOOL_PERMANENT; pool--) {
    mem->small_list[pool] = NULL;
    mem->large_list[pool] = NULL;
  }
  mem->virt_sarray_list = NULL;
  mem->virt_barray_list = NULL;

  mem->total_space_allocated = SIZEOF(my_memory_mgr);

  /* Declare ourselves open for business */
  cinfo->mem = & mem->pub;

	return 0;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jmemnobs.c
 *
 * Copyright (C) 1992-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file provides a really simple implementation of the system-
 * dependent portion of the JPEG memory manager.  This implementation
 * assumes that no backing-store files are needed: all required space
 * can be obtained from malloc().
 * This is very portable in the sense that it'll compile on almost anything,
 * but you'd better have lots of main memory (or virtual memory) if you want
 * to process big images.
 * Note that the max_memory_to_use option is ignored by this implementation.
 */

#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare malloc(),free() */
extern void * malloc JPP((size_t size));
extern void free JPP((void *ptr));
#endif


/*
 * Memory allocation and freeing are controlled by the regular library
 * routines malloc() and free().
 */

GLOBAL(void *)
jpeg_get_small (j_common_ptr cinfo, size_t sizeofobject)
{
  return (void *) malloc(sizeofobject);
}

GLOBAL(void)
jpeg_free_small (j_common_ptr cinfo, void * object, size_t sizeofobject)
{
  free(object);
}


/*
 * "Large" objects are treated the same as "small" ones.
 * NB: although we include FAR keywords in the routine declarations,
 * this file won't actually work in 80x86 small/medium model; at least,
 * you probably won't be able to process useful-size images in only 64KB.
 */

GLOBAL(void  *)
jpeg_get_large (j_common_ptr cinfo, size_t sizeofobject)
{
  return (void  *) malloc(sizeofobject);
}

GLOBAL(void)
jpeg_free_large (j_common_ptr cinfo, void  * object, size_t sizeofobject)
{
  free(object);
}


/*
 * This routine computes the total memory space available for allocation.
 * Here we always say, "we got all you want bud!"
 */

GLOBAL(long)
jpeg_mem_available (j_common_ptr cinfo, long min_bytes_needed,
		    long max_bytes_needed, long already_allocated)
{
  return max_bytes_needed;
}


/*
 * Backing store (temporary file) management.
 * Since jpeg_mem_available always promised the moon,
 * this should never be called and we can just error out.
 */

int jpeg_open_backing_store (j_common_ptr cinfo, backing_store_ptr info,
			 long total_bytes_needed)
{
		jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
}


/*
 * These routines take care of any system-dependent initialization and
 * cleanup required.  Here, there isn't any.
 */

GLOBAL(long)
jpeg_mem_init (j_common_ptr cinfo)
{
  return 0;			/* just set max_memory_to_use to 0 */
}

GLOBAL(void)
jpeg_mem_term (j_common_ptr cinfo)
{
  /* no work */
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jutils.c
 *
 * Copyright (C) 1991-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains tables and miscellaneous utility routines needed
 * for both compression and decompression.
 * Note we prefix all global names with "j" to minimize conflicts with
 * a surrounding application.
 */



/*
 * jpeg_zigzag_order[i] is the zigzag-order position of the i'th element
 * of a DCT block read in natural order (left to right, top to bottom).
 */

#if 0				/* This table is not actually needed in v6a */

const int jpeg_zigzag_order[DCTSIZE2] = {
   0,  1,  5,  6, 14, 15, 27, 28,
   2,  4,  7, 13, 16, 26, 29, 42,
   3,  8, 12, 17, 25, 30, 41, 43,
   9, 11, 18, 24, 31, 40, 44, 53,
  10, 19, 23, 32, 39, 45, 52, 54,
  20, 22, 33, 38, 46, 51, 55, 60,
  21, 34, 37, 47, 50, 56, 59, 61,
  35, 36, 48, 49, 57, 58, 62, 63
};

#endif

/*
 * jpeg_natural_order[i] is the natural-order position of the i'th element
 * of zigzag order.
 *
 * When reading corrupted data, the Huffman decoders could attempt
 * to reference an entry beyond the end of this array (if the decoded
 * zero run length reaches past the end of the block).  To prevent
 * wild stores without adding an inner-loop test, we put some extra
 * "63"s after the real entries.  This will cause the extra coefficient
 * to be stored in location 63 of the block, not somewhere random.
 * The worst case would be a run-length of 15, which means we need 16
 * fake entries.
 */

const int jpeg_natural_order[DCTSIZE2+16] = {
  0,  1,  8, 16,  9,  2,  3, 10,
 17, 24, 32, 25, 18, 11,  4,  5,
 12, 19, 26, 33, 40, 48, 41, 34,
 27, 20, 13,  6,  7, 14, 21, 28,
 35, 42, 49, 56, 57, 50, 43, 36,
 29, 22, 15, 23, 30, 37, 44, 51,
 58, 59, 52, 45, 38, 31, 39, 46,
 53, 60, 61, 54, 47, 55, 62, 63,
 63, 63, 63, 63, 63, 63, 63, 63, /* extra entries for safety in decoder */
 63, 63, 63, 63, 63, 63, 63, 63
};


/*
 * Arithmetic utilities
 */

GLOBAL(long)
jdiv_round_up (long a, long b)
/* Compute a/b rounded up to next integer, ie, ceil(a/b) */
/* Assumes a >= 0, b > 0 */
{
  return (a + b - 1L) / b;
}


GLOBAL(long)
jround_up (long a, long b)
/* Compute a rounded up to next multiple of b, ie, ceil(a/b)*b */
/* Assumes a >= 0, b > 0 */
{
  a += b - 1L;
  return a - (a % b);
}


/* On normal machines we can apply MEMCOPY() and MEMZERO() to sample arrays
 * and coefficient-block arrays.  This won't work on 80x86 because the arrays
 * are FAR and we're assuming a small-pointer memory model.  However, some
 * DOS compilers provide far-pointer versions of memcpy() and memset() even
 * in the small-model libraries.  These will be used if USE_FMEM is defined.
 * Otherwise, the routines below do it the hard way.  (The performance cost
 * is not all that great, because these routines aren't very heavily used.)
 */

#define FMEMCOPY(dest,src,size)	MEMCOPY(dest,src,size)
#define FMEMZERO(target,size)	MEMZERO(target,size)

GLOBAL(void)
jcopy_sample_rows (JSAMPARRAY input_array, int source_row,
		   JSAMPARRAY output_array, int dest_row,
		   int num_rows, JDIMENSION num_cols)
/* Copy some rows of samples from one place to another.
 * num_rows rows are copied from input_array[source_row++]
 * to output_array[dest_row++]; these areas may overlap for duplication.
 * The source and destination arrays must be at least as wide as num_cols.
 */
{
  register JSAMPROW inptr, outptr;
#ifdef FMEMCOPY
  register size_t count = (size_t) (num_cols * SIZEOF(JSAMPLE));
#else
  register JDIMENSION count;
#endif
  register int row;

  input_array += source_row;
  output_array += dest_row;

  for (row = num_rows; row > 0; row--) {
    inptr = *input_array++;
    outptr = *output_array++;
#ifdef FMEMCOPY
    FMEMCOPY(outptr, inptr, count);
#else
    for (count = num_cols; count > 0; count--)
      *outptr++ = *inptr++;	/* needn't bother with GETJSAMPLE() here */
#endif
  }
}


GLOBAL(void)
jcopy_block_row (JBLOCKROW input_row, JBLOCKROW output_row,
		 JDIMENSION num_blocks)
/* Copy a row of coefficient blocks from one place to another. */
{
#ifdef FMEMCOPY
  FMEMCOPY(output_row, input_row, num_blocks * (DCTSIZE2 * SIZEOF(JCOEF)));
#else
  register JCOEFPTR inptr, outptr;
  register long count;

  inptr = (JCOEFPTR) input_row;
  outptr = (JCOEFPTR) output_row;
  for (count = (long) num_blocks * DCTSIZE2; count > 0; count--) {
    *outptr++ = *inptr++;
  }
#endif
}


GLOBAL(void)
jzero_far (void  * target, size_t bytestozero)
/* Zero out a chunk of FAR memory. */
/* This might be sample-array data, block-array data, or alloc_large data. */
{
#ifdef FMEMZERO
  FMEMZERO(target, bytestozero);
#else
  register char  * ptr = (char  *) target;
  register size_t count;

  for (count = bytestozero; count > 0; count--) {
    *ptr++ = 0;
  }
#endif
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * jcomapi.c
 *
 * Copyright (C) 1994-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface routines that are used for both
 * compression and decompression.
 */


/*
 * Abort processing of a JPEG compression or decompression operation,
 * but don't destroy the object itself.
 *
 * For this, we merely clean up all the nonpermanent memory pools.
 * Note that temp files (virtual arrays) are not allowed to belong to
 * the permanent pool, so we will be able to close all temp files here.
 * Closing a data source or destination, if necessary, is the application's
 * responsibility.
 */

GLOBAL(void)
jpeg_abort (j_common_ptr cinfo)
{
  int pool;

  /* Do nothing if called on a not-initialized or destroyed JPEG object. */
  if (cinfo->mem == NULL)
    return;

  /* Releasing pools in reverse order might help avoid fragmentation
   * with some (brain-damaged) malloc libraries.
   */
  for (pool = JPOOL_NUMPOOLS-1; pool > JPOOL_PERMANENT; pool--) {
    (*cinfo->mem->free_pool) (cinfo, pool);
  }

  /* Reset overall state for possible reuse of object */
  if (cinfo->is_decompressor) {
    cinfo->global_state = DSTATE_START;
    /* Try to keep application from accessing now-deleted marker list.
     * A bit kludgy to do it here, but this is the most central place.
     */
    ((j_decompress_ptr) cinfo)->marker_list = NULL;
  } else {
    cinfo->global_state = CSTATE_START;
  }
}


/*
 * Destruction of a JPEG object.
 *
 * Everything gets deallocated except the master jpeg_compress_struct itself
 * and the error manager struct.  Both of these are supplied by the application
 * and must be freed, if necessary, by the application.  (Often they are on
 * the stack and so don't need to be freed anyway.)
 * Closing a data source or destination, if necessary, is the application's
 * responsibility.
 */

void jpeg_destroy (j_common_ptr cinfo) {

	/* We need only tell the memory manager to release everything. */
	/* NB: mem pointer is NULL if memory mgr failed to initialize. */
	if (cinfo->mem != NULL) (*cinfo->mem->self_destruct)(cinfo);
	cinfo->mem = NULL;		/* be safe if jpeg_destroy is called twice */
	cinfo->global_state = 0;	/* mark it destroyed */
}


/*
 * Convenience routines for allocating quantization and Huffman tables.
 * (Would jutils.c be a more reasonable place to put these?)
 */

GLOBAL(JQUANT_TBL *)
jpeg_alloc_quant_table (j_common_ptr cinfo)
{
  JQUANT_TBL *tbl;

  tbl = (JQUANT_TBL *)
    (*cinfo->mem->alloc_small) (cinfo, JPOOL_PERMANENT, SIZEOF(JQUANT_TBL));
  tbl->sent_table = FALSE;	/* make sure this is false in any new table */
  return tbl;
}


GLOBAL(JHUFF_TBL *)
jpeg_alloc_huff_table (j_common_ptr cinfo)
{
  JHUFF_TBL *tbl;

  tbl = (JHUFF_TBL *)
    (*cinfo->mem->alloc_small) (cinfo, JPOOL_PERMANENT, SIZEOF(JHUFF_TBL));
  tbl->sent_table = FALSE;	/* make sure this is false in any new table */
  return tbl;
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

/*
 * djpeg.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains a command-line user interface for the JPEG decompressor.
 * It should work on any system with Unix- or MS-DOS-style command lines.
 *
 * Two different command line styles are permitted, depending on the
 * compile-time switch TWO_FILE_COMMANDLINE:
 *	djpeg [options]  inputfile outputfile
 *	djpeg [options]  [inputfile]
 * In the second style, output is always to standard output, which you'd
 * normally redirect to a file or pipe to some other program.  Input is
 * either from a named file or from standard input (typically redirected).
 * The second style is convenient on Unix but is unhelpful on systems that
 * don't support pipes.  Also, you MUST use the first style if your system
 * doesn't do binary I/O to stdin/stdout.
 * To simplify script writing, the "-outfile" switch is provided.  The syntax
 *	djpeg [options]  -outfile outputfile  inputfile
 * works regardless of which command line style is used.
 */

/* Create the add-on message string table. */

int	exitval=0;

/*
 * Marker processor for COM and interesting APPn markers.
 * This replaces the library's built-in processor, which just skips the marker.
 * We want to print out the marker as text, to the extent possible.
 * Note this code relies on a non-suspending data source.
 */

LOCAL(unsigned int)
jpeg_getc (j_decompress_ptr cinfo)
/* Read next byte */
{
  struct jpeg_source_mgr * datasrc = cinfo->src;
  int retval;

  if (datasrc->bytes_in_buffer == 0) {
    if ( (retval=(*datasrc->fill_input_buffer) (cinfo)) <=0 ) {
		if( retval==0 ) jpeg_destroy((j_common_ptr)&cinfo);
		return -1;
	}
  }
  datasrc->bytes_in_buffer--;
  return GETJOCTET(*datasrc->next_input_byte++);
}


/*
 * The main entry point for loading JPEG files
 */

PBMB LoadJPEG(char *jname, BYTE dir) {

  struct jpeg_decompress_struct cinfo;
  djpeg_dest_ptr dest_mgr = NULL;
  DWORD input_file;
  JDIMENSION num_scanlines;
	BYTE *pL, *pO, b,g,r, **pB;
	int	x, y;

	pX = NULL;
	pXbuf = NULL;
	pB = &pXbuf;

  /* Open the input file. */
	dir |= DIR_LOSSY;

    if( (input_file = Kopen(jname, O_RDBIN, dir)) != -1 ) {
		/* Initialize the JPEG decompression object with default error handling. */
		if( -1==jpeg_create_decompress(&cinfo) ) return NULL;

		/* Specify data source for decompression */
		jpeg_stdio_src(&cinfo, input_file);

		/* Read file header, set default decompression parameters */
		if( -1==jpeg_read_header(&cinfo) ) {
bail:
			Kclose(input_file);
			jpeg_destroy((j_common_ptr)&cinfo);
			if( pX!=NULL ) DeleteBMB(pX);
			if( pXbuf ) free(pXbuf);
			return NULL;
		}

		/* Calculate output image dimensions so we can allocate space */
		jpeg_calc_output_dimensions(&cinfo);

		/* Determine width of rows in the BMP file (padded to 4-byte boundary). */

		// Create the DIB
		if( NULL==(pX=CreateBMB((WORD)cinfo.output_width, (WORD)cinfo.output_height, FALSE)) ) goto bail;


		/* Create decompressor output buffer. */
//		pB = ((*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE, pX->linelen, (JDIMENSION) 1));
		pXbuf = malloc(pX->linelen);
		pB = &pXbuf;
		/* Start decompressor */
		if( -1==jpeg_start_decompress(&cinfo) ) goto bail;

		/* Process data */
		for(y=0; cinfo.output_scanline < cinfo.output_height; y++) {
			if( -1==(num_scanlines = jpeg_read_scanlines(&cinfo, pB, 1)) ) goto bail;

			pO = pX->pBits + pX->linelen * y;
			pL = pXbuf;
			for(x=0; (unsigned int)x<cinfo.output_width; x++) {
				b = *pL++;
				g = *pL++;
				r = *pL++;
				*pO++ = r;
				*pO++ = g;
				*pO++ = b;
			}
		}

		/* Finish decompression and release memory.*/
		if( -1==jpeg_finish_decompress(&cinfo) ) goto bail;

		jpeg_destroy((j_common_ptr)&cinfo);

		/* Close files, if we opened them */
		Kclose(input_file);
	}
  /* All done. */
	return pX;
}
