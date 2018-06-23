<?php

/**
 * @file
 */

/**
 * Get all Yandex Money blocks as objects.
 */
function _ymb_get_all_blocks() {
  return db_select('yamoney_donate_blocks', 'n')
    ->fields('n')
    ->execute();
}

/**
 * Get custom block title from block_custom table.
 */
function _ymb_get_block_title($fieldname, $data) {
  return db_select('block_custom', 'n')
    ->fields('n', ['info'])
    ->condition("n.{$fieldname}", $data)
    ->execute()
    ->fetchField();
}

/**
 * Remove block data from all relative tables.
 */
function _ymb_remove_block_by_bid($bid) {
  db_delete('yamoney_donate_blocks')
    ->condition('bid', $bid)
    ->execute();
  db_delete('block_custom')
    ->condition('bid', $bid)
    ->execute();
  db_delete('block')
    ->condition('module', 'block')
    ->condition('delta', $bid)
    ->execute();
  db_delete('block_role')
    ->condition('module', 'block')
    ->condition('delta', $bid)
    ->execute();
}

/**
 * Generate template Yandex Money Form with data
 */
function _ymb_generate_template($receiver, $target, $sum, $url) {
  return '<form method="POST" action="https://money.yandex.ru/quickpay/confirm.xml">
    <div class="ydb_targets"><label><input type="hidden" name="targets" value="' . $target . '">' . $target . '</label></div>
    <input class="ydb_sum" name="sum" value="' . $sum . '" data-type="number">
    <div class="ydb_pay_type1"><label><input type="radio" name="paymentType" value="PC">Яндекс.Деньгами</label></div>
    <div class="ydb_pay_type2"><label><input type="radio" name="paymentType" value="AC">Банковской картой</label></div>
    <input class="ydb_submit" type="submit" value="Перевести">
    <input class="ydb_hidden" type="hidden" name="receiver" value="' . $receiver . '">
    <input class="ydb_hidden" type="hidden" name="quickpay-form" value="donate">
    <input class="ydb_hidden" type="hidden" name="successURL" value="' . $url . '">
    </form>';
}
