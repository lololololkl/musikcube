//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004-2019 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __C_MUSIKCORE_SDK_C_H__
#define __C_MUSIKCORE_SDK_C_H__

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifdef WIN32
#define mcsdk_export extern "C" __declspec(dllexport)
#else
#define mcsdk_export extern "C"
#endif

/*
 *
 * version
 *
 */

static const int mcsdk_version = 18;

/*
 *
 * constants
 *
 */

enum mcsdk_playback_state {
    mcsdk_playback_stopped = 1,
    mcsdk_playback_paused = 2,
    mcsdk_playback_prepared = 3,
    mcsdk_playback_playing = 4,
};

enum mcsdk_stream_event {
    mcsdk_stream_scheduled = 1,
    mcsdk_stream_prepared = 2,
    mcsdk_stream_playing = 3,
    mcsdk_stream_almost_done = 4,
    mcsdk_stream_finished = 5,
    mcsdk_stream_stopped = 6,
    mcsdk_stream_error = -1
};

enum mcsdk_repeat_mode {
    mcsdk_repeat_none = 0,
    mcsdk_repeat_track = 1,
    mcsdk_repeat_list = 2
};

enum mcsdk_output_code {
    mcsdk_output_error_invalid_format = -4,
    mcsdk_output_error_invalid_state = -3,
    mcsdk_output_error_buffer_full = -2,
    mcsdk_output_error_buffer_written = -1
};

enum mcsdk_time_change_mode {
    mcsdk_time_change_mode_seek = 0,
    mcsdk_time_change_mode_scrub = 1
};

enum mcsdk_path_type {
    mcsdk_path_user_home = 0,
    mcsdk_path_data = 1,
    mcsdk_path_application = 2,
    mcsdk_path_plugins = 3,
    mcsdk_path_library = 4
};

enum mcsdk_stream_capability {
    mcsdk_stream_capability_prebuffer = 0x01
};

enum mcsdk_indexer_scan_result {
    mcsdk_indexer_scan_result_commit = 1,
    mcsdk_indexer_scan_result_rollback = 2
};

enum class mcsdk_replay_gain_mode {
    mcsdk_replay_gain_mode_disabled = 0,
    mcsdk_replay_gain_mode_track = 1,
    mcsdk_replay_gain_mode_album = 2
};

enum class mcsdk_transport_type {
    mcsdk_transport_type_gapless = 0,
    mcsdk_transport_type_crossfade = 1
};

enum mcsdk_stream_open_flags {
    mcsdk_stream_open_flags_none = 0,
    mcsdk_stream_open_flags_read = 1,
    mcsdk_stream_open_flags_write = 2
};

enum mcsdk_resource_class {
    mcsdk_resource_type_value = 0,
    mcsdk_resource_type_map = 1
};

static const size_t mcsdk_equalizer_band_count = 18;

static const size_t mcsdk_equalizer_bands[] = {
    65, 92, 131, 185, 262, 370, 523, 740, 1047, 1480,
    2093, 2960, 4186, 5920, 8372, 11840, 16744, 22000
};

static const int mcsdk_no_offset = 0;
static const int mcsdk_no_limit = -1;

static const char* mcsdk_category_type_album = "album";
static const char* mcsdk_category_type_artist = "artist";
static const char* mcsdk_category_type_album_artist = "album_artist";
static const char* mcsdk_category_type_genre = "genre";
static const char* mcsdk_category_type_playlist = "playlists";

static const char* mcsdk_track_field_id = "id";
static const char* mcsdk_track_field_track_num = "track";
static const char* mcsdk_track_field_disc_num = "disc";
static const char* mcsdk_track_field_bpm = "bpm";
static const char* mcsdk_track_field_duration = "duration";
static const char* mcsdk_track_field_filesize = "filesize";
static const char* mcsdk_track_field_year = "year";
static const char* mcsdk_track_field_title = "title";
static const char* mcsdk_track_field_filename = "filename";
static const char* mcsdk_track_field_thumbnail_id = "thumbnail_id";
static const char* mcsdk_track_field_album = "album";
static const char* mcsdk_track_field_album_artist = "album_artist";
static const char* mcsdk_track_field_genre = "genre";
static const char* mcsdk_track_field_artist = "artist";
static const char* mcsdk_track_field_filetime = "filetime";
static const char* mcsdk_track_field_genre_id = "visual_genre_id";
static const char* mcsdk_track_field_artist_id = "visual_artist_id";
static const char* mcsdk_track_field_album_artist_id = "album_artist_id";
static const char* mcsdk_track_field_album_id = "album_id";
static const char* mcsdk_track_field_source_id = "source_id";
static const char* mcsdk_track_field_external_id = "external_id";

/*
 *
 * types
 *
 */

mcsdk_export typedef void* mcsdk_handle;
mcsdk_export typedef mcsdk_handle mcsdk_resource;
mcsdk_export typedef mcsdk_handle mcsdk_value;
mcsdk_export typedef mcsdk_handle mcsdk_value_list;
mcsdk_export typedef mcsdk_handle mcsdk_map;
mcsdk_export typedef mcsdk_handle mcsdk_track;
mcsdk_export typedef mcsdk_handle mcsdk_map_list;
mcsdk_export typedef mcsdk_handle mcsdk_track_list;
mcsdk_export typedef mcsdk_handle mcsdk_track_list_editor;
mcsdk_export typedef mcsdk_handle mcsdk_svc_metadata;

/*
 *
 * IResource
 *
 */

mcsdk_export int64_t mcsdk_resource_get_id(mcsdk_resource r);
mcsdk_export mcsdk_resource_class mcsdk_resource_get_class(mcsdk_resource r);
mcsdk_export void mcsdk_resource_release(mcsdk_resource r);

/*
 *
 * IValue
 *
 */

mcsdk_export size_t mcsdk_value_get_value(mcsdk_value v, char* dst, size_t size);
mcsdk_export void mcsdk_value_release(mcsdk_value v);

/*
 *
 * IValueList
 *
 */

mcsdk_export size_t mcsdk_value_list_count(mcsdk_value_list vl);
mcsdk_export mcsdk_value mcsdk_value_list_get_at(mcsdk_value_list vl, size_t index);
mcsdk_export void mcsdk_value_list_release(mcsdk_value_list vl);

/*
 *
 * IMap
 *
 */

mcsdk_export int mcsdk_map_get_string(mcsdk_map m, const char* key, char* dst, int size);
mcsdk_export int64_t mcsdk_map_get_int64(mcsdk_map m, const char* key, int64_t default_value);
mcsdk_export int32_t mcsdk_map_get_int32(mcsdk_map m, const char* key, int32_t default_value);
mcsdk_export double mcsdk_map_get_double(mcsdk_map m, const char* key, double default_value);
mcsdk_export void mcsdk_map_release(mcsdk_map m);

/*
 *
 * IMapList
 *
 */

mcsdk_export size_t mcsdk_map_list_get_count(mcsdk_map_list ml);
mcsdk_export mcsdk_map_list mcsdk_map_list_get_at(mcsdk_map_list ml, size_t index);
mcsdk_export void mcsdk_map_list_release(mcsdk_map_list ml);

/*
 *
 * ITrack
 *
 */

mcsdk_export void mcsdk_track_retain(mcsdk_track t);
mcsdk_export int mcsdk_track_get_uri(mcsdk_track t, char* dst, int size);
mcsdk_export void mcsdk_track_release(mcsdk_track t);

/*
 *
 * ITrackList
 *
 */

mcsdk_export size_t mcsdk_track_list_get_count(mcsdk_track_list tl);
mcsdk_export int64_t mcsdk_track_list_get_id(mcsdk_track_list tl, size_t index);
mcsdk_export int64_t mcsdk_track_list_index_of(mcsdk_track_list tl, int64_t id);
mcsdk_export mcsdk_track mcsdk_track_list_get_track_at(mcsdk_track_list tl, size_t index);
mcsdk_export void mcsdk_track_list_release(mcsdk_track_list tl);

/*
 *
 * ITrackListEditor
 *
 */

mcsdk_export bool mcsdk_track_list_editor_insert(mcsdk_track_list_editor tle, int64_t id, size_t index);
mcsdk_export bool mcsdk_track_list_editor_swap(mcsdk_track_list_editor tle, size_t index1, size_t index2);
mcsdk_export bool mcsdk_track_list_editor_move(mcsdk_track_list_editor tle, size_t from, size_t to);
mcsdk_export bool mcsdk_track_list_editor_delete(mcsdk_track_list_editor tle, size_t index);
mcsdk_export void mcsdk_track_list_editor_add(mcsdk_track_list_editor tle, const int64_t id);
mcsdk_export void mcsdk_track_list_editor_clear(mcsdk_track_list_editor tle);
mcsdk_export void mcsdk_track_list_editor_shuffle(mcsdk_track_list_editor tle);
mcsdk_export void mcsdk_track_list_editor_release(mcsdk_track_list_editor tle);

/*
 *
 * IMetadataProxy
 *
 */

mcsdk_export mcsdk_track_list mcsdk_svc_metadata_query_tracks(mcsdk_svc_metadata mp, const char* keyword, int limit, int offset);
mcsdk_export mcsdk_track mcsdk_svc_metadata_query_track_by_id(mcsdk_svc_metadata mp, int64_t track_id);
mcsdk_export mcsdk_track mcsdk_svc_metadata_query_track_by_external_id(mcsdk_svc_metadata mp, const char* external_id);
mcsdk_export mcsdk_track_list mcsdk_svc_metadata_query_tracks_by_category(mcsdk_svc_metadata mp, const char* category_type, int64_t selected_id, const char* filter, int limit, int offset);
mcsdk_export mcsdk_track_list mcsdk_svc_metadata_query_tracks_by_categories(mcsdk_svc_metadata mp, mcsdk_value* categories, size_t category_count, const char* filter, int limit, int offset);
mcsdk_export mcsdk_track_list mcsdk_svc_metadata_query_tracks_by_external_id(mcsdk_svc_metadata mp, const char** external_ids, size_t external_id_count);
mcsdk_export mcsdk_value_list mcsdk_svc_metadata_list_categories(mcsdk_svc_metadata mp);
mcsdk_export mcsdk_value_list mcsdk_svc_metadata_query_category(mcsdk_svc_metadata mp, const char* type, const char* filter);
mcsdk_export mcsdk_value_list mcsdk_svc_metadata_query_category_with_predicate(mcsdk_svc_metadata mp, const char* type, const char* predicate_type, int64_t predicate_id, const char* filter);
mcsdk_export mcsdk_value_list mcsdk_svc_metadata_query_category_with_predicates(mcsdk_svc_metadata mp, const char* type, mcsdk_value* predicates, size_t predicate_count, const char* filter);
mcsdk_export mcsdk_map_list mcsdk_svc_metadata_query_albums(mcsdk_svc_metadata mp, const char* filter);
mcsdk_export mcsdk_map_list mcsdk_svc_metadata_query_albums_by_category(mcsdk_svc_metadata mp, const char* category_id_name, int64_t category_id_value, const char* filter);
mcsdk_export int64_t mcsdk_svc_metadata_save_playlist_with_ids(mcsdk_svc_metadata mp, int64_t* track_ids, size_t track_id_count, const char* playlist_name, const int64_t playlist_id);
mcsdk_export int64_t mcsdk_svc_metadata_save_playlist_with_external_ids(mcsdk_svc_metadata mp, const char** external_ids, size_t external_id_count, const char* playlist_name, const int64_t playlist_id);
mcsdk_export int64_t mcsdk_svc_metadata_save_playlist_with_track_list(mcsdk_svc_metadata mp, mcsdk_track_list track_list, const char* playlist_name, const int64_t playlist_id);
mcsdk_export bool mcsdk_svc_metadata_rename_playlist(mcsdk_svc_metadata mp, const int64_t playlist_id, const char* playlist_name);
mcsdk_export bool mcsdk_svc_metadata_delete_playlist(mcsdk_svc_metadata mp, const int64_t playlist_id);
mcsdk_export bool mcsdk_svc_metadata_append_to_playlist_with_ids(mcsdk_svc_metadata mp, const int64_t playlist_id, const int64_t* track_ids, size_t track_id_count, int offset);
mcsdk_export bool mcsdk_svc_metadata_append_to_playlist_with_external_ids(mcsdk_svc_metadata mp, const int64_t playlist_id, const char** external_track_ids, size_t external_track_id_count, int offset);
mcsdk_export bool mcsdk_svc_metadata_append_to_playlist_with_track_list(mcsdk_svc_metadata mp, const int64_t playlist_id, mcsdk_track_list track_list, int offset);
mcsdk_export size_t mcsdk_svc_metadata_remove_tracks_from_playlist(mcsdk_svc_metadata mp, const int64_t playlist_id, const char** external_ids, const int* sort_orders, int count);
mcsdk_export void mcsdk_svc_metadata_release(mcsdk_svc_metadata mp);

#endif